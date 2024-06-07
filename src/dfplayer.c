#include <xc.h>
#include <stdint.h>
#include "dfplayer.h"
#include "uart.h"

static void execute_CMD(uint8_t CMD, uint8_t Par1, uint8_t Par2){
    uint16_t checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
    uint8_t highByteOfChecksum = checksum >> 8;
    uint8_t lowByteOfChecksum = checksum ;
    uint8_t Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD,
    Acknowledge, Par1, Par2, highByteOfChecksum, lowByteOfChecksum, End_Byte};
    for (uint8_t k = 0; k < 10; k++){
        UART_Send( Command_line[k]);
    }
    __delay_ms(11); 
}

void playNext(){
    execute_CMD(0x01,0,0);
    __delay_ms(500);
}

void playPrevious(){
    execute_CMD(0x02,0,0);
    __delay_ms(500);
}

void play(){
    execute_CMD(0x0D,0,0); 
    __delay_ms(500);
}

void pause(){
    execute_CMD(0x0E,0x0,0x0);
    __delay_ms(500);
}

void setVolume(uint8_t volume)
{
    execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
    __delay_ms(2000);
}

void playFirst(){
    setVolume(5);
    __delay_ms(500);
    execute_CMD(0x03,0x0,0x05); 
    __delay_ms(500);
}