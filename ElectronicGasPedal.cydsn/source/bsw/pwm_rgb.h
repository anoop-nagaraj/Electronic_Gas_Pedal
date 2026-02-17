/**
* \file pwm_rgb.h
* \author Anoop K N
* \date 29-05-2022
*
* \brief BSW header file for PWM component
*
* This file provides the function declarations for PWM driver component which controls ONLY
* the Green channel of the RGB led
* ToDo: Expand the code to service all the channels of the RGB led
*
* \note <notes>
* ===================================================================
**/
 
#ifndef PWM_ENGINE_RGB_H
#define PWM_ENGINE_RGB_H

#include "global.h"
#include "derivate.h"
    
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
 * \brief       : API to initialize the PWM component
 * \param       : NONE
 * \return      : RC_t Returns error code success or failure
 */
RC_t PWM_RGB_init();

/**
 * \brief       : API to vary the intensity of the Green channel in RGB led
 * \param [IN]  : uint8_t engine_data - Engine speed
 * \return      : RC_t Returns error code success or failure
 */
RC_t PWM_Green_setIntensity(uint8_t engine_data);
/*****************************************************************************/
/* Private stuff, only visible for Together, declared static in cpp - File   */
/*****************************************************************************/


#endif /* FILE_H */
