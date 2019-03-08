![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# LPG Click

---

- **CIC Prefix**  : LPG
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Jan 2019.

---

### Software Support

We provide a library for the LPG Click on our [LibStock](https://libstock.mikroe.com/projects/view/1043/lpg-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control LPG Click board.
LPG click communicates with the target board via analog ( AN ) pin. 
This library contains drivers for read ADC value of MQ-5B sensor.

Key functions :

- ``` float lpg_voltageConversion( uint32_t adcValue, float vRef ) ``` - Convert the voltage function
- ``` float lpg_getRatio( uint32_t adcValue, float vRef ) ``` - Get the sensor ratio function
- ``` float lpg_getSensorResistance( uint32_t adcValue, float vRef ) ``` - Get the sensor resistance

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN pin as input.
- Application Initialization - Initialization driver enables GPIO and ADC, also starts write log.
- Application Task - (code snippet) This is a example which demonstrates the use of LPG Click board.
     LPG Click reads ADC value. Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart changes for every 1 sec.


```.c

void applicationTask()
{
    valueADC = lpg_readADC();

    IntToStr( valueADC, logText );
    mikrobus_logWrite( " ADC value: ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    Delay_1sec();
}

```

Additional Functions :

- void lpg_adcInit() - Function ADC initialization.
- uint32_t lpg_readADC() - Function read ADC value.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1043/lpg-click-example) page.

Other mikroE Libraries used in the example:

- ADC
- UART
- Conversion

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
