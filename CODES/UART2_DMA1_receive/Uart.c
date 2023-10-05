#include "stm32f401re.h"
#include <stdint.h>
#include "Uart.h"
#include <string.h>

extern uint8_t RX_buffer[];
extern uint8_t Main_buffer[];
extern uint8_t indx;

void Usart2Config(){
	RCC_APB1ENR |= (1<<17); // UART clock enable
	RCC_AHB1ENR |= (1<<0); //GPIO clock enable
	GPIOA_MODER |= (2<<4) | (2<<6); // configure GPIO pins as Alternate function mode
	GPIOA_OSPEEDR |= (3<<4) | (3<<6); // GPIO high speed config
	GPIOA_AFRL |= (7<<8) | (7<<12); // Altarnate functions selected as USART
	USART2_CR1 = 0x00; // Clear USART control register
	USART2_CR1 &= ~(1<<12); // configuration of Word length to 8 bits
	USART2_CR1 |= (1<<13); // USART enable
	USART2_CR3 |= (1<<6); //DMA receive enable
	USART2_BRR = 365; // Baud rate config to 115200
	USART2_CR1 |= (1<<3); // enable trasmitter
	USART2_CR1 |= (1<<2); // enable receiver
}
void DMA_init(){
	RCC_AHB1ENR |= (1<<21); // Enable DMA clock
	DMA1_S5CR |= (1<<1) | (1<<2) | (1<<3) | (1<<4); //Enable DMA Interrupts
	DMA1_S5CR |= (1<<8); // Enable the circular mode 
	DMA1_S5CR |= (1<<10); // Enable automatic memory location incrementation
	DMA1_S5CR |= (4<<25); // Channel 4 selected
}
void DMA_config(uint32_t srcAdd, uint32_t dstAdd, uint16_t datasize){
	DMA1_S5NDTR = datasize;
	DMA1_S5PAR = srcAdd;
	DMA1_S5M0AR = dstAdd;
	DMA1_S5CR |= (1<<0); // Stream enable
}

void DMA1_Stream5_IRQHandler(void){
	if(DMA1_HISR & (1<<10)){
		memcpy(&Main_buffer[indx],&RX_buffer[0],20/2);
		DMA1_HIFCR |= (1<<10);
		indx = indx+(20/2);
		if (indx>50-1) 
		indx=0;
	}
	if(DMA1_HISR & (1<<11)){
		memcpy(&Main_buffer[indx],&RX_buffer[20/2],20/2);
		DMA1_HIFCR |= (1<<11);
		indx = indx+(20/2);
		if (indx>50-1) 
		indx=0;
	}
}
void Usart2_SendChar(uint8_t c){
	USART2_DR = c; // load data to data register
	while(!(USART2_SR & (1<<6)));
}
void Usart2_Transmit(char *tempstring){

	while(*tempstring)
	Usart2_SendChar(*tempstring++);
}
uint8_t Usart2_GetChar(void){
	uint8_t temp;
	while (!(USART2_SR & (1<<5))); // wait for RXNE bit to set
	temp = USART2_DR;
	return temp;
}
void Usart2_Receive(uint8_t* buffer, uint32_t size) {
    uint32_t i = 0;
    while (i < size) {
        while (!(USART2_SR & (1<<5)));
        buffer[i] = (uint8_t)(USART2_DR & (uint8_t)0x00FF); // get first 8 bits then reset the others
        i++;
    }
}

void Usart1Config(){
	RCC_APB2ENR |= (1<<4); // UART clock enable
	RCC_AHB1ENR |= (1<<0); //GPIO clock enable
	GPIOA_MODER |= (2<<18) | (2<<20); // configure GPIO pins as Alternate function mode
	GPIOA_OSPEEDR |= (3<<18) | (3<<20); // GPIO high speed config
	GPIOA_AFRH |= (7<<4) | (7<<8); // Altarnate functions selected as USART
	USART1_CR1 = 0x00; // Clear USART control register
	USART1_CR1 |= (1<<13); // USART enable
	USART1_CR1 &= ~(1<<12); // configuration of Word length to 8 bits
	USART1_BRR = 729; // Baud rate config to 115200
	USART1_CR1 |= (1<<3); // enable trasmitter
	USART1_CR1 |= (1<<2); // enable receiver
}
void Usart1_SendChar(uint8_t c){
	USART1_DR = c; // load data to data register
	while(!(USART1_SR & (1<<6)));
}
void Usart1_Transmit(char *tempstring){

	while(*tempstring)
	Usart1_SendChar(*tempstring++);
}
uint8_t Usart1_GetChar(void){
	uint8_t temp;
	while (!(USART1_SR & (1<<5))); // wait for RXNE bit to set
	temp = USART1_DR;
	return temp;
}
void Usart1_Receive(uint8_t* buffer, uint32_t size) {
    uint32_t i = 0;
    while (i < size) {
        while (!(USART1_SR & (1<<5)));
        buffer[i] = (uint8_t)(USART1_DR & (uint8_t)0x00FF);
        i++;
    }
}
