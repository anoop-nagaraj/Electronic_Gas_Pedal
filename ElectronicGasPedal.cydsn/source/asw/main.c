/* ========================================
 *
 * Copyright  YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "global.h"

#include "tsk_control.h"
#include "tsk_io.h"
#include "pwm_rgb.h"
#include "adc.h"
#include "uart.h"
#include "watchdog.h"

//Variable to read the reset status of the watchdog bit
#define BITFIELD_MASK                0xF
#define WDG_RESET_REGISTER           0x08

volatile boolean_t WDG_RESET_BIT;


//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    WD_Start(WDT_1024_TICKS);
    UART_init();
    
    //Fetch the watchdog reset bit
    WDG_RESET_BIT = WD_CheckResetBit();
    
    //Reset occured by watchdog or by POR
    if(TRUE == WDG_RESET_BIT)
    {
        UART_Log_Tx ("System reset occured by Watchdog");
    }
    else
    {
        UART_Log_Tx ("Power ON Reset");
    }

    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
    
    UART_Log_Tx("In main function");
   
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    //Init MCAL Drivers
    ADC_init();
    PWM_RGB_init();
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
	
    //Start the alarm with 1ms cycle time
    SetRelAlarm(alrm_1ms,1,1);
    
    ActivateTask(tsk_system);
    ActivateTask(tsk_io);
    ActivateTask(tsk_control);
    ActivateTask(tsk_background);
    
    TerminateTask();
    
}

TASK(tsk_background)
{
    while(1)
    {
        //do something with low prioroty
        //UART_Joystick_PutString("In background task");
        if(bitField == BITFIELD_MASK)
        {
            WD_Trigger();
        }
        else
        {
            CY_SET_REG8(CYDEV_RESET_SR0, WDG_RESET_REGISTER);
        } 
    }
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/
ISR2(isr_wdgButton)
{
    //Call the OS Shutdown function
    //E_OK indicates that the shutdown was called by the user
    ShutdownOS(E_OK);
    
}