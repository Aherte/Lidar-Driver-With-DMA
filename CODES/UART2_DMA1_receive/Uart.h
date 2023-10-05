#if !defined(UART)
#define UART

void Usart2Config();
void Usart2_SendChar(uint8_t c);
void Usart2_Transmit(char *tempstring);
uint8_t Usart2_GetChar(void);
void Usart2_Receive(uint8_t* buffer, uint32_t size) ;

void DMA_config(uint32_t srcAdd, uint32_t dstAdd, uint16_t datasize);
void DMA_init();

void Usart1Config();
void Usart1_SendChar(uint8_t c);
void Usart1_Transmit(char *tempstring);
uint8_t Usart1_GetChar(void);
void Usart1_Receive(uint8_t* buffer, uint32_t size) ;
#endif // UART