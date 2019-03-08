#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC0_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_9 );
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC0_Get_Sample( 9 );
    
    return readADC;
}