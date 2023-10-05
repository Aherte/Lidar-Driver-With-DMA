#include <stdint.h>
#include "Uart.h"
#include "stm32f401re.h"
#include "Delay.h"
#include "string.h"
#include "Interrupt.h"


uint8_t RX_buffer[20];
uint8_t Main_buffer[50];
uint8_t indx = 0;

uint8_t RXdata[9] = {0};


int main(void){
	SytemClock_Configuration();
	TimerSetup();
	Usart2Config ();
	DMA_init ();
	NVIC_SetPriority (DMA1_Stream5_IRQn, 0);
	NVIC_EnableIRQ (DMA1_Stream5_IRQn);
	DMA_config ((uint32_t) &USART2_DR, (uint32_t) RX_buffer, 20);
while(1){
	

}

}
