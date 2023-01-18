#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	unsigned int count = 0b00000001;
    LEDarray_init();
    while (1) {
        for (int i=0; i < 7; i++) {
            count = count << 1;
            LEDarray_disp_bin(count);
            __delay_ms(100);
        }
        for (int i=0; i < 7; i++) {
            count = count >> 1;
            LEDarray_disp_bin(count);// 
            __delay_ms(100);
        }
    }
}
