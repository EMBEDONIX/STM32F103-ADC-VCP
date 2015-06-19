#ifndef __SERIAL_DEBUGGER_H
#define __SERIAL_DEBUGGER_H

#include "usart.h"

void SD_PutChar(USART_TypeDef* USARTx, uint8_t ch);

void SD_PutString(USART_TypeDef* USARTx, uint8_t* message);

void SD_PutNumber(USART_TypeDef* USARTx, uint32_t x);

void SD_PutFormatted(USART_TypeDef* USARTx, uint8_t* message);

#endif