#include <stdint.h>
#include "Uart.h"
#include "stm32f401re.h"
#include "Delay.h"
#include "string.h"

uint8_t RXdata[9] = {0};
uint16_t distance =0;
uint16_t strenght =0;

uint8_t Calculate_Checksum(uint8_t *data , uint8_t size)
{
	int i;
	int sum =0;
	for(i=0;i<size-1;i++){
		sum = sum+data[i];
	}
	return sum & 0xFF;
}
void Calculate_Lidar(void){
	strenght = (RXdata[5]<<8) | RXdata[4];
	uint8_t checksum = Calculate_Checksum(RXdata , sizeof(RXdata));
	if(checksum == RXdata[8])
	distance = (RXdata[3]<<8) | RXdata[2];
}
int main(void){
	SytemClock_Configuration();
	TimerSetup();
	Usart1Config();

while(1){
	Usart1_Receive(RXdata,9);
	Calculate_Lidar();
}

}
