/*
    __lpg_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __lpg_driver.h
@brief    LPG Driver
@mainpage LPG Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   LPG
@brief      LPG Click Driver
@{

| Global Library Prefix | **LPG** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LPG_H_
#define _LPG_H_

/** 
 * @macro T_LPG_P
 * @brief Driver Abstract type 
 */
#define T_LPG_P    const uint8_t*

/** @defgroup LPG_COMPILE Compilation Config */              /** @{ */

//  #define   __LPG_DRV_SPI__                            /**<     @macro __LPG_DRV_SPI__  @brief SPI driver selector */
//  #define   __LPG_DRV_I2C__                            /**<     @macro __LPG_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LPG_DRV_UART__                           /**<     @macro __LPG_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LPG_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup LPG_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LPG_INIT Driver Initialization */              /** @{ */

#ifdef   __LPG_DRV_SPI__
void lpg_spiDriverInit(T_LPG_P gpioObj, T_LPG_P spiObj);
#endif
#ifdef   __LPG_DRV_I2C__
void lpg_i2cDriverInit(T_LPG_P gpioObj, T_LPG_P i2cObj, uint8_t slave);
#endif
#ifdef   __LPG_DRV_UART__
void lpg_uartDriverInit(T_LPG_P gpioObj, T_LPG_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void lpg_gpioDriverInit(T_LPG_P gpioObj);
                                                                       /** @} */
/** @defgroup LPG_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Convert the voltage function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the voltage
 *
 * Function returns voltage from the analog input value
 * refer ADC conversion for further reference
 * of MQ-5 sensor on LPG Click.
*/
float lpg_voltageConversion( uint32_t adcValue, float vRef );

/**
 * @brief Get the sensor ratio function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the sensor ratio
 *
 * Function get the ratio of MQ-5 sensor on LPG Click.
*/
float lpg_getRatio( uint32_t adcValue, float vRef );

/**
 * @brief Get the sensor resistance
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @param[in] vRef                           the VREF value ( 3.3V or 5V )
 *
 * @return
 * float value of the sensor resistance
 *
 * Function get the resistance of MQ-5 sensor on LPG Click.
*/
float lpg_getSensorResistance( uint32_t adcValue, float vRef );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_LPG_STM.c
    @example Click_LPG_TIVA.c
    @example Click_LPG_CEC.c
    @example Click_LPG_KINETIS.c
    @example Click_LPG_MSP.c
    @example Click_LPG_PIC.c
    @example Click_LPG_PIC32.c
    @example Click_LPG_DSPIC.c
    @example Click_LPG_AVR.c
    @example Click_LPG_FT90x.c
    @example Click_LPG_STM.mbas
    @example Click_LPG_TIVA.mbas
    @example Click_LPG_CEC.mbas
    @example Click_LPG_KINETIS.mbas
    @example Click_LPG_MSP.mbas
    @example Click_LPG_PIC.mbas
    @example Click_LPG_PIC32.mbas
    @example Click_LPG_DSPIC.mbas
    @example Click_LPG_AVR.mbas
    @example Click_LPG_FT90x.mbas
    @example Click_LPG_STM.mpas
    @example Click_LPG_TIVA.mpas
    @example Click_LPG_CEC.mpas
    @example Click_LPG_KINETIS.mpas
    @example Click_LPG_MSP.mpas
    @example Click_LPG_PIC.mpas
    @example Click_LPG_PIC32.mpas
    @example Click_LPG_DSPIC.mpas
    @example Click_LPG_AVR.mpas
    @example Click_LPG_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __lpg_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */