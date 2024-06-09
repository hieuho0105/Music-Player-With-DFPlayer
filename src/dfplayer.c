#include <xc.h>
#include <stdint.h>
#include "dfplayer.h"
#include "uart.h"

static void execute_CMD(uint8_t CMD, uint8_t Par1, uint8_t Par2) {
    uint16_t checksum = -(VERSION_BYTE + COMMAND_LENGTH + CMD + ACKNOWLEDGE + Par1 + Par2);
    uint8_t highByteOfChecksum = checksum >> 8;
    uint8_t lowByteOfChecksum = checksum ;
    uint8_t Command_line[10] = { START_BYTE, VERSION_BYTE, COMMAND_LENGTH, CMD,
    ACKNOWLEDGE, Par1, Par2, highByteOfChecksum, lowByteOfChecksum, END_BYTE};
    for (uint8_t k = 0; k < 10; k++) {
        UART_Send(Command_line[k]);
    }
    __delay_ms(11); 
}

void playNext() {
    execute_CMD(CMD_PLAY_NEXT,0,0);
    __delay_ms(500);
}

void playPrevious() {
    execute_CMD(CMD_PLAY_PREVIOUS,0,0);
    __delay_ms(500);
}

void play() {
    execute_CMD(CMD_PLAY,0,0); 
    __delay_ms(500);
}

void pause() {
    execute_CMD(CMD_PAUSE,0,0);
    __delay_ms(500);
}

void setVolume(uint8_t volume) {
    execute_CMD(CMD_SET_VOLUME, 0, volume); // Set the volume (0x00~0x30)
    __delay_ms(500);
}

void playFirst() {
    setVolume(5);
    __delay_ms(500);
    execute_CMD(CMD_PLAY_FIRST,0x0,0x05); 
    __delay_ms(500);
}