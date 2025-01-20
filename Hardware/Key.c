#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void Key_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOB的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//将PB1和PB11引脚初始化为上拉输入
}


uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;		//定义变量，默认键码值为0
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 1)			//读PB1输入寄存器的状态，如果为1，则代表按键按下
	{
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 1);										
		KeyNum = ~KeyNum;												
	}
	
	return KeyNum;			//返回键码值，如果没有按键按下，if不成立，则键码为默认值0
}
