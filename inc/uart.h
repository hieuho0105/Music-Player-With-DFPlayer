#ifndef UART_H
#define UART_H

#include <stdint.h>

void UART_Init(uint32_t BAUDRATE);
void UART_Send(char cmd);

#endif /* UART_H */