#include "serial_debugger.h"
#include "stm32f103xb.h"

void SD_PutChar(USART_TypeDef* USARTx, uint8_t ch)
{
  while(!(USARTx->SR & USART_SR_TXE));
  USARTx->DR = ch;  
}

void SD_PutString(USART_TypeDef* USARTx, uint8_t * str)
{
  while(*str != 0)
  {
    SD_PutChar(USARTx, *str);
    str++;
  }
}

void SD_PutNumber(USART_TypeDef* USARTx, uint32_t x)
{
  char value[10];
  int i;
  
  i = 0;
  
  do
  {
    value[i++] = (char)(x % 10) + '0';
    x /= 10;
  } while(x);
  
  while(i)
  {
    while (!(USARTx->SR & USART_SR_TXE)); // check that USART is ready
    SD_PutChar(USARTx, value[--i]); //send data
  }
  
  while (!(USARTx->SR & USART_SR_TXE)); // check that USART is ready
  SD_PutChar(USARTx, '\n'); //send newline
}

void SD_PutFormatted(USART_TypeDef* USARTx, uint8_t* message)
{
  //NOT IMPLEMENTED
}