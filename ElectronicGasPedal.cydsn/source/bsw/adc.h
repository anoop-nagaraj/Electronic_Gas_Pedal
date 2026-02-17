/**
* \file adc.h
* \author Anoop K N
* \date 27-05-2022
*
* \brief Header file for ADC component
*
* detailed description what the file does
*
* \note <notes>
* ===================================================================
**/
 
#ifndef ADC_H
#define ADC_H

#include "global.h"
#include "derivate.h"

#include "ADC_JoyStick.h"
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
 * @brief       : API to initialize the ADC component
 * @param [OUT] : int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return      : RC_t Returns error code success or failure
 */
RC_t ADC_init();

/**
 * @brief       : API to get converted values from ADC
 * @param [OUT] : int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return      : RC_t Returns error code success or failure
 */
RC_t ADC_getValue(int8_t *const adc_value);

//RC_t JOYSTICK_ReadPosition(sint8_t* x, sint8_t* y);
/*****************************************************************************/
/* Private stuff, only visible for Together, declared static in cpp - File   */
/*****************************************************************************/


#endif /* FILE_H */
