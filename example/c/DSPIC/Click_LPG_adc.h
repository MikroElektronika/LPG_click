#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC1_Init_Advanced(_ADC_12bit, _ADC_INTERNAL_VREFL | _ADC_INTERNAL_VREFH );
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}