#include "stm32f10x.h"                  // Device header

void Sensor_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PA1、PA4引脚初始化为上拉输入
}

uint8_t Get_RSensor(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);	//返回PA1输入寄存器的状态
}

uint8_t Get_LSensor(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);	//返回PA4输入寄存器的状态
}
