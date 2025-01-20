#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "Sensor.h"
#include "LED.h"
#include <stdint.h>

int main(void)
{
	uint8_t left_sensor, right_sensor;
	
	Motor_Init();
	Sensor_Init();
	LED_Init();
	
	while(1)
	{
		left_sensor = Get_LSensor();
		right_sensor = Get_RSensor();
		
		if(left_sensor != 1 && right_sensor != 1)
		{
			Forword();
			LED4_ON();
			LED5_ON();
		}
		else if(left_sensor != 1 && right_sensor == 1)
		{
			Turn_Left();
			LED4_ON();
			LED5_OFF();
		}
		else if(right_sensor != 1 &&left_sensor == 1)
		{
			Turn_Right();
			LED4_OFF();
			LED5_ON();
		}
		else
		{
			Stop();
			LED4_OFF();
			LED5_OFF();
		}
	}
}
