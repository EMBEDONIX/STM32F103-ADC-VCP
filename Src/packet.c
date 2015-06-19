/**
  ******************************************************************************
  * File Name          : communication_manager.h
  * Description        : This file provides implementation of managing a message
  *                      buffer
  *
  * Author             : Saeid Yazdani [saeid@embedonix.com]
  * Date               : 11-6-2015
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 EMBEDONIX GmbH
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  *****************************************************************************/

#include "packet.h"

CM_Packet cmHandler;

void CM_Init(CM_Packet *handler) {
	handler->StartByte = CM_START_BYTE;
	handler->StopByte =  CM_STOP_BYTE;
}

void CM_AppendData(CM_Packet *handler, uint8_t identifier,
                              uint32_t data){

    switch(identifier){
      case CM_VALUE_0: //adc11
		  handler->Value0 = data;
        break;

      case CM_VALUE_1:
    	  handler->Value1 = data;
        break;

      case CM_VALUE_2:
    	  handler->Value2 = data;
        break;

      case CM_VALUE_3:
    	  handler->Value3 = data;
        break;

    default:

      break;
    }
}

uint16_t CalculateCRC16(uint16_t crc, const void *c_ptr, uint32_t len){

    const uint8_t *c = c_ptr;

    while (len--)
        crc = (crc << 8) ^ CM_CRC16_TABLE[((crc >> 8) ^ *c++)];

    return crc;
}
