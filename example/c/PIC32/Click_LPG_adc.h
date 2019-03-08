#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC1_Init();
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}