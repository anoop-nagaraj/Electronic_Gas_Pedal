/**
* \file adc.c
* \author Anoop K N
* \date 27-05-2022
*
* \brief Source file for ADC component
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
#include "adc.h"

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
 * @brief       : API to initialize the ADC component
 * @param [OUT] : int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return      : RC_t Returns error code success or failure
 */
RC_t ADC_init()
{
    //Start the ADC component
    ADC_JoyStick_Start();
    ADC_JoyStick_StartConvert();
   
    return RC_SUCCESS;
}

/**
 * @brief       : API to get converted values from ADC
 * @param [OUT] : int8_t *const adc_value - Digital converted value of the input to the ADC
 * @return      : RC_t Returns error code success or failure
 */
RC_t ADC_getValue(int8_t *const adc_value)
{
    //Check for end of conversion and read out the digital value from ADC
    if(ADC_JoyStick_IsEndConversion(ADC_JoyStick_WAIT_FOR_RESULT))
    {
        *adc_value = ADC_JoyStick_GetResult8();
        return RC_SUCCESS;
    }  
    else
    {
        return RC_ERROR;
    }
}

//RC_t JOYSTICK_ReadPosition(sint8_t* x, sint8_t* y)
//{
//    //Wait for end of conversion
//    ADC_JoyStick_IsEndConversion(ADC_JoyStick_WAIT_FOR_RESULT);
//    
//    //Read channels
//    uint16_t posX = ADC_JoyStick_GetResult16(0);
//    uint16_t posY = ADC_JoyStick_GetResult16(1);
//    
//    //Convert to scaled 8bit signal
//    *x = (sint8_t)((2048 - posX) / 16);
//    *y = (sint8_t)(((2048 - posY) / 16)-120);
//    
//    return RC_SUCCESS;
//}