/**
* \file uart.c
* \author Anoop K N
* \date 29-05-2022
*
* \brief Source file for BSW UART component
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
#include "uart.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

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
 * @brief: API to initialize the UART component
 * @param [OUT]: int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return RC_t Returns error code success or failure
 */
RC_t UART_init ()
{
    UART_Joystick_Start();
    return RC_SUCCESS;
}

/**
 * @brief       : API to get converted values from ADC
 * @param [IN]  : const char - String input to be printed on the terminal
 * @return      : RC_t Returns error code success or failure
 */
RC_t UART_Log_Tx(const char* logString)
{
    UART_Joystick_PutString(logString);
    UART_Joystick_PutString("\r\n");
    
    CyDelay(200);
    
    return RC_SUCCESS;
}
