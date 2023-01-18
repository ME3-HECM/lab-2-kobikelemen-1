#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void setup_button(void) {
    // sets up button pins for input
    TRISFbits.TRISF2 = 1;
    ANSELFbits.ANSELF2 = 0;
    
}


void main(void) 
{    
    unsigned int count = 0;
    LEDarray_init();
    setup_button();
    while (1) {
        if (!PORTFbits.RF2) {
            count ++; // increment count whenever button is pressed
        }
        LEDarray_disp_bin(count);
        __delay_ms(100);
    }
}
