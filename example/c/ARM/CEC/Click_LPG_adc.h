#include "Click_LPG_types.h"


void lpg_adcInit()
{
    ADC1_Init();
    ADC_Set_Input_Channel( 0x01 );
}

uint32_t lpg_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 1 );
    
    return readADC;
}