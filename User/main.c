#include "stm32f10x.h"                  // Device header
#include "Delay.h"
const uint8_t Light[7] = {0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	GPIO_Write(GPIOA, 0xFF);
	
	while(1)
	{
		uint16_t i;
		for(i = 0; i < 7; i++)
		{
			GPIO_Write(GPIOA, Light[i]);
			Delay_s(1);
		}
	}
}
