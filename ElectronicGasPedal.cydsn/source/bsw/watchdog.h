/**
* \file watchdog.h
* \author Anoop K N
* \date 30-05-2022
*
* \brief Header file for Watchdog configuration
*
*
* \note <notes>
* ===================================================================
*/

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "global.h"
#include "derivate.h"

/*****************************************************************************/
/* Global pre-processor symbols/macros and type declarations                 */
/*****************************************************************************/

//####################### Defines/Macros
/* Low power mode configuration. This parameter is ignored for PSoC 5.
 * The WDT always acts as if CYWDT_LPMODE_NOCHANGE is passed.
 */
#define WDT_LPMODE_NOCHANGE       (0x00u)

//####################### Enumerations
/* Watchdog timer ticks for Central Timewheel
 * One of the four available timer periods. Once WDT enabled, the
 * interval cannot be changed.
 */
typedef enum
{
    WDT_2_TICKS,                /* (0x00u)    4ms - 6ms    */
    WDT_16_TICKS,               /* (0x01u)   32ms - 48ms   */
    WDT_128_TICKS,              /* (0x02u)  256ms - 324ms  */
    WDT_1024_TICKS              /* (0x03u) 2048ms - 3072ms */
}WDT_TimeOut_t;

/*****************************************************************************/
/* Extern global variables                                                   */
/*****************************************************************************/
// Global bitfield mask to check the BitPosition set by the runnables
extern uint8_t bitField;

/*****************************************************************************/
/* API functions                                                             */
/*****************************************************************************/

/**
 * \brief        : Activate the Watchdog Trigger
 * \param        : WDT_TimeOut_t timeout - [IN] Timeout Period
 * @return       : RC_SUCCESS
**/
RC_t WD_Start(WDT_TimeOut_t timeout);

/**
 * \brief        : Service the Watchdog Trigger
 * \param        : NONE
 * @return       : RC_SUCCESS
**/
RC_t WD_Trigger();

/**
 * \brief        : Checks the watchdog bit
 * \param        : NONE
 * @return TRUE if watchdog reset bit was set
**/
boolean_t WD_CheckResetBit();

/**
 * \brief        : Set the bit in corresponding bitposition of the bitfield
 * \param [IN]   : uint8_t myBitPosition - bitPosition of individual runnables
 * @return SUCCESS/FAILURE
 */
RC_t WD_Alive(uint8_t myBitPosition);

/*****************************************************************************/
/* Private stuff, only visible for Together, declared static in cpp - File   */
/*****************************************************************************/


#endif /* WATCHDOG_H */
