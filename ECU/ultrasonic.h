/*
 * ultrasonic.h
 *
 * Created: 09/08/2022 12:18:18 م
 *  Author: Mahmoud Abdelmoniem
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "../MCAL/timer1/timer1.h"
#include "../MCAL/GPIO/GPIO.h"






typedef struct  
{
	pin_cofig_t echo;
	pin_cofig_t trigger;
}ultrasonic_t;

Std_ReturnType UltraSonic_Init(const ultrasonic_t* ultra);
Std_ReturnType Ultrasonic_GetDistance(const ultrasonic_t* ultra,uint8 *_distance); 
uint8 ULTRASONIC_GetDistanceNoBlock(uint8*Pdistance); 
#endif /* ULTRASONIC_H_ */