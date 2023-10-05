#include "stm32f401re.h"
#include <stdint.h>
#include "Uart.h"

void Usart2Config(){
	RCC_APB1ENR |= (1<<17); // UART clock enable
	RCC_AHB1ENR |= (1<<0); //GPIO clock enable
	GPIOA_MODER |= (2<<4) | (2<<6); // configure GPIO pins as Alternate function mode
	GPIOA_OSPEEDR |= (3<<4) | (3<<6); // GPIO high speed config
	GPIOA_AFRL |= (7<<8) | (7<<12); // Altarnate functions selected as USART
	USART2_CR1 = 0x00; // Clear USART control register
	USART2_BRR = 365; // Baud rate config to 115200
	USART2_CR1 |= (1<<3); // enable trasmitter
	USART2_CR1 |= (1<<2); // enable receiver
	USART2_CR1 |= (1<<13); // USART enable
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
	USART1_BRR = 729; // Baud rate config to 115200
	USART1_CR1 |= (1<<3); // enable trasmitter
	USART1_CR1 |= (1<<2); // enable receiver
	USART1_CR1 |= (1<<13); // USART enable
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
        buffer[i] = (uint8_t)(USART1_DR & (uint8_t)0x00FF);// get first 8 bits then reset the others
        i++;
    }
}
