#include <stdint.h>
#include "Delay.h"
#include "stm32f401re.h"

void SytemClock_Configuration(void){
	RCC_CR |= (1<<0); // hsi ON
	while(!(RCC_CR & (1<<1))); // wait for hsi ready
	FLASH_ACR |= (1<<10) | (1<<9) | (1<<8) | (1<<1); // Prefetch and latency settings
	RCC_PLLCFGR &= ~(1<<22); // PLL source mux HSI
	RCC_PLLCFGR = (PLLM << 0) | (PLLN << 6) | (PLLP << 16); // PLL configurations BEFORE PLL:ON
	RCC_CR |= (1<<24); // PLL ON
	while (!(RCC_CR & (1<<25))); // wait for PLL ready
	RCC_CFGR &= ~(3 << 0); // SW[1:0] clean 
	RCC_CFGR |= (2 << 0);  // SW[1:0] set SW bits as [1:0]
	while ((RCC_CFGR & (3 << 2)) != (2 << 2)); // waiting for correction from SWS bits
	RCC_CFGR &= ~((15 << 4) | (7 << 10) | (7 << 13)); // Reset (APB1,APB2,AHB)
	RCC_CFGR |= (1 << 12); // APB1 /2

}
void TimerSetup(void){
	RCC_APB1ENR |= (1<<1); // timer 3 enable
	TIM3_PSC = 84-1; //To generate 1 uS we should divide 84MHz with 84
	TIM3_ARR = 0xffff; // max arr value which can reset the timer if we assign a number 
	TIM3_CR1 |= (1<<0); // enable the counter
	while (!(TIM3_SR & (1<<0))); // wait for the overflow interrupt 
}
void Delay_us (uint16_t time){
	TIM3_CNT = 0; // Set counter to 0
	while(TIM3_CNT < time); //wait until the counter reach given value

}
void Delay_ms (uint16_t time){
	for(uint16_t i=0; i<time ; i++){
		Delay_us(1000);
	}
}