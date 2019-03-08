/*
Example for LPG Click

    Date          : Jan 2019.
    Author        : Nenad Filipovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN pin as input.
- Application Initialization - Initialization driver enables GPIO and ADC, also starts write log.
- Application Task - (code snippet) This is a example which demonstrates the use of LPG Click board.
     LPG Click reads ADC value. Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart changes for every 1 sec.

Additional Functions :

- void lpg_adcInit() - Function ADC initialization.
- uint32_t lpg_readADC() - Function read ADC value.

*/

#include "Click_LPG_types.h"
#include "Click_LPG_config.h"
#include "Click_LPG_adc.h"


uint32_t valueADC;
char logText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    lpg_gpioDriverInit( (T_LPG_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( "     LPG click     ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    lpg_adcInit();
    Delay_100ms();

    mikrobus_logWrite( "   Initializated   ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
}

void applicationTask()
{
    valueADC = lpg_readADC();
    Delay_1sec();

    IntToStr( valueADC, logText );
    mikrobus_logWrite( " ADC value: ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}