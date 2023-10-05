#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE  (96U * 1024U) // 96kb
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END
extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

// main in prototipi
int main(void);

void Reset_handler(void);  // void Reset_handler(void) __attribute__ ((section(".rand_section"))); random section oluşturur ve     resethandler yazısını o sectiona yazar.
void NMI_handler(void)             __attribute__ ((weak, alias("Default_handler")));
void HardFault_handler(void)       __attribute__ ((weak, alias("Default_handler")));
void MemManage_Handler(void)       __attribute__ ((weak, alias("Default_handler")));
void BusFault_Handler(void)       __attribute__ ((weak, alias("Default_handler")));
void UsageFault_Handler(void)      __attribute__ ((weak, alias("Default_handler")));
void SVC_Handler(void)            __attribute__ ((weak, alias("Default_handler")));
void DebugMon_Handler(void)            __attribute__ ((weak, alias("Default_handler")));
void PendSV_Handler(void)            __attribute__ ((weak, alias("Default_handler")));
void SysTick_Handler(void)            __attribute__ ((weak, alias("Default_handler")));
void WWDG_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void PVD_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TAMP_STAMP_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void RTC_WKUP_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void FLASH_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void RCC_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI0_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI1_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI3_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI4_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream0_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream1_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream3_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream4_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream5_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream6_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void ADC_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI9_5_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM1_BRK_TIM9_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM1_UP_TIM10_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM1_CC_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM3_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM4_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C1_EV_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C1_ER_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C2_EV_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C2_ER_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void SPI1_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void SPI2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void USART1_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void USART2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void EXTI15_10_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void RTC_Alarm_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void OTG_FS_WKUP_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA1_Stream7_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void SDIO_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void TIM5_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void SPI3_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream0_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream1_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream2_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream3_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream4_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void OTG_FS_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream5_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream6_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void DMA2_Stream7_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void USART6_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C3_EV_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void I2C3_ER_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void FPU_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));
void SPI4_IRQHandler(void)            __attribute__ ((weak, alias("Default_handler")));


uint32_t vectors[] __attribute__ ((section(".isr_vector"))) ={
	STACK_START,
	(uint32_t)&Reset_handler,
	(uint32_t)&NMI_handler,
	(uint32_t)&HardFault_handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)&WWDG_IRQHandler,
	(uint32_t)&PVD_IRQHandler,
	(uint32_t)&TAMP_STAMP_IRQHandler,
	(uint32_t)&RTC_WKUP_IRQHandler,
	(uint32_t)&FLASH_IRQHandler,
	(uint32_t)&RCC_IRQHandler,
	(uint32_t)&EXTI0_IRQHandler,
	(uint32_t)&EXTI1_IRQHandler,
	(uint32_t)&EXTI2_IRQHandler,
	(uint32_t)&EXTI3_IRQHandler,
	(uint32_t)&EXTI4_IRQHandler,
	(uint32_t)&DMA1_Stream0_IRQHandler,
	(uint32_t)&DMA1_Stream1_IRQHandler,
	(uint32_t)&DMA1_Stream2_IRQHandler,
	(uint32_t)&DMA1_Stream3_IRQHandler,
	(uint32_t)&DMA1_Stream4_IRQHandler,
	(uint32_t)&DMA1_Stream5_IRQHandler,
	(uint32_t)&DMA1_Stream6_IRQHandler,
	(uint32_t)&ADC_IRQHandler,
	0,
	0,
	0,
	0,
	(uint32_t)&EXTI9_5_IRQHandler,
	(uint32_t)&TIM1_BRK_TIM9_IRQHandler,
	(uint32_t)&TIM1_UP_TIM10_IRQHandler,
	(uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,
	(uint32_t)&TIM1_CC_IRQHandler,
	(uint32_t)&TIM2_IRQHandler,
	(uint32_t)&TIM3_IRQHandler,
	(uint32_t)&TIM4_IRQHandler,
	(uint32_t)&I2C1_EV_IRQHandler,
	(uint32_t)&I2C1_ER_IRQHandler,
	(uint32_t)&I2C2_EV_IRQHandler,
	(uint32_t)&I2C2_ER_IRQHandler,
	(uint32_t)&SPI1_IRQHandler,
	(uint32_t)&SPI2_IRQHandler,
	(uint32_t)&USART1_IRQHandler,
	(uint32_t)&USART2_IRQHandler,
	0,
	(uint32_t)&EXTI15_10_IRQHandler,
	(uint32_t)&RTC_Alarm_IRQHandler,
	(uint32_t)&OTG_FS_WKUP_IRQHandler,
	0,
	0,
	0,
	0,
	(uint32_t)&DMA1_Stream7_IRQHandler,
	0,
	(uint32_t)&SDIO_IRQHandler,
	(uint32_t)&TIM5_IRQHandler,
	(uint32_t)&SPI3_IRQHandler,
	0,
	0,
	0,
	0,
	(uint32_t)&DMA2_Stream0_IRQHandler,
	(uint32_t)&DMA2_Stream1_IRQHandler,
	(uint32_t)&DMA2_Stream2_IRQHandler,
	(uint32_t)&DMA2_Stream3_IRQHandler,
	(uint32_t)&DMA2_Stream4_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	(uint32_t)&OTG_FS_IRQHandler,
	(uint32_t)&DMA2_Stream5_IRQHandler,
	(uint32_t)&DMA2_Stream6_IRQHandler,
	(uint32_t)&DMA2_Stream7_IRQHandler,
	(uint32_t)&USART6_IRQHandler,
	(uint32_t)&I2C3_EV_IRQHandler,
	(uint32_t)&I2C3_ER_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	(uint32_t)&FPU_IRQHandler,
	0,
	0,
	(uint32_t)&SPI4_IRQHandler,
};
void Reset_handler(void){
	// copy .data section to SRAM
	
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata;  // sram	
	uint8_t *pSrc = (uint8_t*)&_etext;  // flash
	
	for(uint32_t i=0 ; i < size ; i++){
	
	  	*pDst++ = *pSrc++ ;
	}
	// init .bss section to zero in SRAM
	
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	
	pDst = (uint8_t*)&_sbss;  
	
	for(uint32_t i=0 ; i < size ; i++){
	
	  	*pDst++ = 0 ;
	}
	
	// call the main
	main();
}
void Default_handler(void){
	while(1);
}

