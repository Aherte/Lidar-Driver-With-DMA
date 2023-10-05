#if !defined(STM32F401RE)
#define STM32F401RE

#define GPIOA_BASE 0x40020000
#define RCC_BASE 0x40023800
#define POWER_BASE 0x40007000
#define FLASH_BASE 0x40023C00
#define TIMER3_BASE 0x40000400
#define USART2_BASE 0x40004400
#define USART1_BASE 0x40011000

#define PLLM 8
#define PLLN 84
#define PLLP 0 // PLLP = 2

#define RCC_CR *(volatile uint32_t*)(RCC_BASE + 0x00)
#define RCC_AHB1ENR *(volatile uint32_t*)(RCC_BASE + 0x30)
#define RCC_APB1ENR *(volatile uint32_t*)(RCC_BASE + 0x40)
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x44)
#define RCC_CFGR *(volatile uint32_t*)(RCC_BASE + 0x08)
#define RCC_PLLCFGR *(volatile uint32_t*)(RCC_BASE + 0x04)

#define GPIOA_AFRL *(volatile uint32_t*)(GPIOA_BASE + 0x20)
#define GPIOA_AFRH *(volatile uint32_t*)(GPIOA_BASE + 0x24)
#define GPIOA_BSSR *(volatile uint32_t*)(GPIOA_BASE + 0x18)
#define GPIOA_MODER *(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_OSPEEDR *(volatile uint32_t*)(GPIOA_BASE + 0x08)
#define GPIOA_ODR *(volatile uint32_t*)(GPIOA_BASE + 0x14)

#define PWR_CR *(volatile uint32_t*)(POWER_BASE + 0x00)

#define FLASH_ACR *(volatile uint32_t*)(FLASH_BASE + 0x00)

#define TIM3_PSC *(volatile uint32_t*)(TIMER3_BASE + 0x28)
#define TIM3_ARR *(volatile uint32_t*)(TIMER3_BASE + 0x2C)
#define TIM3_CR1 *(volatile uint32_t*)(TIMER3_BASE + 0x00)
#define TIM3_SR *(volatile uint32_t*)(TIMER3_BASE + 0x10)
#define TIM3_CNT *(volatile uint32_t*)(TIMER3_BASE + 0x24)

#define USART2_CR1 *(volatile uint32_t*)(USART2_BASE + 0x0C)
#define USART2_BRR *(volatile uint32_t*)(USART2_BASE + 0x08)
#define USART2_DR *(volatile uint32_t*)(USART2_BASE + 0x04)
#define USART2_SR *(volatile uint32_t*)(USART2_BASE + 0x00)

#define USART1_CR1 *(volatile uint32_t*)(USART1_BASE + 0x0C)
#define USART1_BRR *(volatile uint32_t*)(USART1_BASE + 0x08)
#define USART1_DR *(volatile uint32_t*)(USART1_BASE + 0x04)
#define USART1_SR *(volatile uint32_t*)(USART1_BASE + 0x00)

#endif // STM32F401RE


