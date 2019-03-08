#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC_Init();
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}