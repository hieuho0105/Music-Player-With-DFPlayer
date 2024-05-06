#include "uart.h"
#include <xc.h>

void UART_Init(uint32_t baudrate){     
    TRISCbits.TRISC6 = 0;  //TX 
    TRISCbits.TRISC7 = 1;  //RX 
      
    SPBRG = (uint8_t)((_XTAL_FREQ/(64.0*baudrate))-1);
    TXSTA = 0x20;
    
    RCSTA = 0x90;  
    RCIE  = 1;    
}

void UART_Send(char cmd){
    while(TXSTAbits.TRMT==0);
    TXREG = cmd;
}