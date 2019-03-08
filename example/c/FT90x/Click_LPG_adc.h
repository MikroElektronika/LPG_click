#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC_Init();
	ADC_Set_Input_Channel( _ADC_CHANNEL_4 );
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 4 );
    
    return readADC;
}