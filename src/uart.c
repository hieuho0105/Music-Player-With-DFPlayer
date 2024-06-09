#include <pic16f877.h>
#include <stdint.h>
#include "config.h"
#include "uart.h"

void UART_Init(uint32_t baudrate) {     
    TRISCbits.TRISC6 = 0;  //TX: output
    TRISCbits.TRISC7 = 1;  //RX: input
    
    SPBRG = (uint8_t)((_XTAL_FREQ/(64.0*baudrate))-1); //SPBRG for 9600 baudrate
    TXSTA = 0x20; // TX enable BRGH=1
    
    RCSTA = 0x90;  // Serial Port enable SPEN=1, CREN=1 
    RCIE  = 1;     // Enable UART interrupt
}

void UART_Send(char cmd) {
    while(TXSTAbits.TRMT==0); // Wait for the Transmit Buffer to become empty
    TXREG = cmd; // Transmit the data
}