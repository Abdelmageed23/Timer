/*
 * main.c
 *
 *  Created on: Jan 4, 2022
 *      Author: Abdelrahman Mohamed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_interface.h"
#include "Interrupt_interface.h"
#include "LED_interface.h"


volatile uint8_t count=0;

void Test1(void)
{

	/* 	ON Timer	300ms
	 * overflow time =32.768 ms
	 * Desired time = 300ms
	 * no. of over flow 10
	 * Initial value 216
	 *
	 * OFF TIME		500ms
	 * overflow time =32.768 ms
	 * Desired time = 500ms
	 * no. of over flow 16
	 * Initial value 189
	 */

	if (count == 10)

		{
		 LED_OFF(LED_PORTB,7);
		 Timer0_Start(190);
		}

		else if( count ==26)
		{
			LED_ON(LED_PORTB,7);
			Timer0_Start(216);
			count =0;
		}


		count++;
}

void main()

{

	 GlobalInerruptEnable();
	 LED_Init(LED_PORTB,5);
	 LED_Init(LED_PORTB,7);

	 	 LED_ON(LED_PORTB,5);
	 	 Timer0_Init();
	 	 Timer0_Start(216);
	 	 Timer0_OvfISR(&Test1);

	 	 Timer2_Init();


	 while(1)
	 {
		 LED_ON(LED_PORTB,5);
		 Timer2_SetBusyWait(2343);
		 LED_OFF(LED_PORTB,5);
		 Timer2_SetBusyWait(3906);

	 }
}

