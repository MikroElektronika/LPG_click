/*
    __lpg_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__lpg_driver.h"
#include "__lpg_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LPG_DRV_I2C__
static uint8_t _slaveAddress;
#endif
const float _LPG_VREF_3_3                                               = 3.3;
const float _LPG_VREF_5_0                                               = 5.0;
const float _LPG_COEFFICIENT_A                                          = 19.32;
const float _LPG_COEFFICIENT_B                                          = -0.64;
const float _LPG_R_LOAD                                                 = 10.0;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LPG_DRV_SPI__

void lpg_spiDriverInit(T_LPG_P gpioObj, T_LPG_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LPG_DRV_I2C__

void lpg_i2cDriverInit(T_LPG_P gpioObj, T_LPG_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LPG_DRV_UART__

void lpg_uartDriverInit(T_LPG_P gpioObj, T_LPG_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void lpg_gpioDriverInit(T_LPG_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */



/* Convert the voltage function */
float lpg_voltageConversion( uint32_t adcValue, float vRef )
{
    float result;

    result = ( float ) adcValue;
    result *= vRef;
    result /= 1023.0;

    return result;
}

/* Get the sensor ratio function */
float lpg_getRatio( uint32_t adcValue, float vRef )
{
    float result;
    float vOut;

    vOut = lpg_voltageConversion( adcValue, vRef );

    result = vOut - vRef;
    result /= vOut;

    return result;
}

/* Get the sensor resistance */
float lpg_getSensorResistance( uint32_t adcValue, float vRef )
{
    float result;

    result = _LPG_R_LOAD;
    result *= lpg_getRatio( adcValue, vRef );

    return result;
}



/* -------------------------------------------------------------------------- */
/*
  __lpg_driver.c

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