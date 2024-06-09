/*
 * File:   main.c
 * Author: HO CONG HIEU
 *
 * Created on June 3, 2023, 7:11 PM
 */
#include <xc.h>
#include <stdint.h>
#include "config.h"
#include "dfplayer.h"
#include "uart.h"

#define IS_PUSH  0
#define BUTTON_NEXT      PORTBbits.RB5
#define BUTTON_PAUSE     PORTBbits.RB6
#define BUTTON_PREVIOUS  PORTBbits.RB7

#define _XTAL_FREQ 20000000 // 20MHz
#define BAUDRATE 9600


void main(void) {
    
    TRISB = 0xFF; // Set PORTB as input
    UART_Init(BAUDRATE); // Initialize UART module with 9600 baudrate
    __delay_ms(1500);
    playFirst(); // Play the first song
    bool isPlaying;
    isPlaying = true;
    
    while(true) {
   
        if (BUTTON_PAUSE == IS_PUSH) {
            while(BUTTON_PAUSE == IS_PUSH); // Wait until the button is released
            if(isPlaying) {
                pause();
                isPlaying = false;
            } else {
                isPlaying = true;
                play();
            }
        }

        if (BUTTON_NEXT == IS_PUSH) {
            while(BUTTON_NEXT == IS_PUSH); // Wait until the button is released
            if(isPlaying){
                playNext();
            }
        }
        
        if (BUTTON_PREVIOUS == IS_PUSH) {
            while(BUTTON_PREVIOUS == IS_PUSH); // Wait until the button is released
            if(isPlaying){
                playPrevious();
            }
        }
    } 
}
