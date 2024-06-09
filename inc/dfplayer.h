#ifndef DFPLAYER_H
#define DFPLAYER_H

#include <stdint.h>

#define START_BYTE 0x7E
#define VERSION_BYTE 0xFF
#define COMMAND_LENGTH 0x06
#define END_BYTE 0xEF
#define ACKNOWLEDGE 0x00

#define CMD_PLAY_NEXT 0x01
#define CMD_PLAY_PREVIOUS 0x02
#define CMD_PLAY_FIRST 0x03
#define CMD_PLAY 0x0D
#define CMD_PAUSE 0x0E
#define CMD_SET_VOLUME 0x06



void execute_CMD(uint8_t CMD, uint8_t Par1, uint8_t Par2);
void playNext();
void playPrevious();
void play();
void pause();
void setVolume(uint8_t volume);
void playFirst();

#endif /* DFPLAYER_H */