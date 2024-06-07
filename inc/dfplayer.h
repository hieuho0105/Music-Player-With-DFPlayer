#ifndef DFPLAYER_H
#define DFPLAYER_H

#include <stdint.h>

#define Start_Byte 0x7E
#define Version_Byte 0xFF
#define Command_Length 0x06
#define End_Byte 0xEF
#define Acknowledge 0x00



void execute_CMD(uint8_t CMD, uint8_t Par1, uint8_t Par2);
void playNext();
void playPrevious();
void play();
void pause();
void setVolume(uint8_t volume);
void playFirst();

#endif /* DFPLAYER_H */