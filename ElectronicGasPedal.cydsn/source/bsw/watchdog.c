/**
* \file watchdog.c
* \author Anoop K N
* \date 29-05-2022
*
* \brief Source file Watchdog driver component in BSW
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "watchdog.h"
#include "CyLib.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/
#define WATCHDOG_RST_REG_VALUE      0x08
/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/
uint8_t bitField = 0;
/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/
typedef enum
{
    JOYSTICK_RUNNABLE,
    CONTROL_RUNNABLE,
    ENGINE_RUNNABLE,
    BRAKELIGHT_RUNNABLE
}runnableList;
/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/**
 * \brief        : Activate the Watchdog Trigger
 * \param        : WDT_TimeOut_t timeout - [IN] Timeout Period
 * @return       : RC_SUCCESS
**/
RC_t WD_Start(WDT_TimeOut_t timeout)
{
    CyWdtStart(timeout, WDT_LPMODE_NOCHANGE);
    return RC_SUCCESS;
}

/**
 * \brief        : Service the Watchdog Trigger
 * \param        : NONE
 * @return       : RC_SUCCESS
**/
RC_t WD_Trigger()
{
    //Clears the PM_WDT_CR register of the watchdog timer
    CyWdtClear();
    return RC_SUCCESS;
}

/**
 * \brief        : Checks the watchdog bit
 * \param        : NONE
 * @return TRUE if watchdog reset bit was set
**/
boolean_t WD_CheckResetBit()
{
    //Local variable to fetch the watchdog reset register value
    uint8_t wdgResetRegister = 0;
    
    //Fetch the value in the reset register using the system function
    // https://community.cypress.com/t5/PSoC-5-3-1-MCU/PSoC-5LP-WDT-Reset-Detection/m-p/230974
    wdgResetRegister = CY_GET_REG8(CYREG_PHUB_CFGMEM23_CFG1);//CYDEV_RESET_SR0);
    
    /*
     * CYDEV_RESET_SR0[3] is set on the occurence of a watchdog reset
     * It remains set until cleared by the user, by reading or writing to the register
     * Or until a POR (Power ON Reset).
     */
    if ((wdgResetRegister & WATCHDOG_RST_REG_VALUE) == WATCHDOG_RST_REG_VALUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * \brief        : Set the bit in corresponding bitposition of the bitfield
 * \param [IN]   : uint8_t myBitPosition - bitPosition of individual runnables
 * @return SUCCESS/FAILURE
 */
RC_t WD_Alive(uint8_t myBitPosition)
{
    bitField = bitField | myBitPosition;
    return RC_SUCCESS;    
}
