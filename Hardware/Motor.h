#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_Init(void);
void Motor_SetSpeed(uint8_t L_Speed, uint8_t R_Speed);
void Forword(void);
void Turn_Left(void);
void Turn_Right(void);
void Stop(void);

#endif
