#include "stm32f10x.h"                  // Device header
#include "PWM.h"


void Motor_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//开启GPIOA的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//将PB12、PB13、PB14、PB15引脚初始化为推挽输出	
	
	PWM_Init();													//初始化直流电机的底层PWM
}


void Motor_SetSpeed(uint8_t L_Speed, uint8_t R_Speed)
{
		if (L_Speed < 25) L_Speed = 25; // 防止低速失速
		if (R_Speed < 25) R_Speed = 25; // 防止低速失速
	
		GPIO_SetBits(GPIOB, GPIO_Pin_13);	//PB13置高电平
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//PB12置低电平
		PWM_SetCompare1(L_Speed);			//PWM设置为速度值
	
		GPIO_SetBits(GPIOB, GPIO_Pin_15);	//PB15置高电平
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);	//PB14置低电平
		PWM_SetCompare2(R_Speed);			//PWM设置为速度值
}

void Forword(void)
{
	Motor_SetSpeed(70,70);
}

void Turn_Left(void)
{
	Motor_SetSpeed(50,30);
}

void Turn_Right(void)
{
	Motor_SetSpeed(30,50);
}

void Stop(void)
{
	Motor_SetSpeed(0,0);
}
