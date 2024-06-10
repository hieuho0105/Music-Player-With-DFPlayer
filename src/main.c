/*
 * File:   main.c
 * Author: HO CONG HIEU
 *
 * Created on June 3, 2023, 7:11 PM
 */
#include <pic16f877.h>
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


void __interrupt() ISR(void) {
    // Kiểm tra nguồn ngắt là từ INT0
    if (INTCONbits.INTF) {
        if (BUTTON_PAUSE == IS_PUSH) {
            while(BUTTON_PAUSE == IS_PUSH); // Chờ cho đến khi nút bấm được thả ra
            if(isPlaying) {
                pause();
                isPlaying = false;
            } else {
                isPlaying = true;
                play();
            }
        } else if (BUTTON_NEXT == IS_PUSH) {
            while(BUTTON_NEXT == IS_PUSH); // Chờ cho đến khi nút bấm được thả ra
            if(isPlaying){
                playNext();
            }
        } else if (BUTTON_PREVIOUS == IS_PUSH) {
            while(BUTTON_PREVIOUS == IS_PUSH); // Chờ cho đến khi nút bấm được thả ra
            if(isPlaying){
                playPrevious();
            }
        }
        // Xóa cờ ngắt INT0
        INTCONbits.INTF = 0;
    }
}


void main(void) {
    
    TRISB = 0xFF; // Set PORTB là input
    UART_Init(BAUDRATE); // Khởi tạo UART với baudrate 9600
    __delay_ms(1500);

    // Cấu hình ngắt ioc cho các nút bấm (BUTTON_NEXT, BUTTON_PAUSE, BUTTON_PREVIOUS)
    INTCONbits.RBIE = 1;   // Cho phép ngắt trên thay đổi
    INTCONbits.RBIF = 0;   // Xóa cờ ngắt RBIF
    IOCB = 0xFF;           // Bật ngắt trên thay đổi cho tất cả các chân RB
    // Cấu hình ngắt chung
    INTCONbits.GIE = 1;    // Cho phép ngắt chung
    INTCONbits.PEIE = 1;   // Cho phép ngắt ngoại vi

    playFirst(); // Phát nhạc đầu tiên
    bool isPlaying;
    isPlaying = true; // Biến kiểm tra trạng thái phát nhạc
    
    while(true) {
        // do nothing
    } 
}
