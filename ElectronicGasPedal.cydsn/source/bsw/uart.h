/**
* \file uart.h
* \author Anoop K N
* \date 29-05-2022
*
* \brief BSW file for UART component
*
* detailed description what the file does
*
* \note <notes>
* ===================================================================
**/

#ifndef UART_H
#define UART_H

#include "global.h"
#include "derivate.h"

#include "UART_Joystick.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros and type declarations                 */
/*****************************************************************************/

//####################### Defines/Macros

//####################### Enumerations

//####################### Structures


/*****************************************************************************/
/* Extern global variables                                                   */
/*****************************************************************************/

/*****************************************************************************/
/* API functions                                                             */
/*****************************************************************************/

/**
 * @brief       : API to initialize the UART component
 * @param [OUT] : int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return      : RC_t Returns error code success or failure
 */
RC_t UART_init();

/**
 * @brief       : API to get converted values from ADC
 * @param [IN]  : const char - String input to be printed on the terminal
 * @return      : RC_t Returns error code success or failure
 */
RC_t UART_Log_Tx(const char* logString);
/*****************************************************************************/
/* Private stuff, only visible for Together, declared static in cpp - File   */
/*****************************************************************************/


#endif /* UART_H */
