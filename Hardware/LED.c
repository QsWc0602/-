#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOB的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//将PB3、PB4、PB5引脚初始化为推挽输出
	
	/*设置GPIO初始化后的默认电平*/
	GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);  //设置PB3、PB4、PB5引脚为高电平
}

void LED3_ON(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_3);		//设置PB3引脚高为电平
}

void LED3_OFF(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);		//设置PB3引脚为低电平
}

void LED4_ON(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_4);		//设置PB4引脚高为电平
}

void LED4_OFF(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);		//设置PB4引脚为低电平
}
void LED5_ON(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_5);		//设置PB5引脚高为电平
}

void LED5_OFF(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);		//设置PB5引脚为低电平
}
