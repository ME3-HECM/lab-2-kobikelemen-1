#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"


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
    int held = 0; // is button held
    while (1) {
        if (!PORTFbits.RF2) {
            if (held == 0) { // only increment if button wasn't held at previous iteration
                count ++; 
            }
            LEDarray_disp_dec(count);
            __delay_ms(500);
            while (!PORTFbits.RF2) { // if button is still held after 500ms, increment count continously
                count ++;
                LEDarray_disp_dec(count);
                __delay_ms(50);
            }
            held = 1; // button was held if in this if statement, so set to 1
        } else { // no signal means button not held
            held = 0;
        }
        LEDarray_disp_dec(count);
    }
}
