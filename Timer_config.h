/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 6 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/********************************* TIMER0 ***************************************/
/*	NORMAL
 * 	CTC
 * 	PWM_PHASE_CORRECT
 * 	FAST_PWM
 */
#define  Timer0_Mode NORMAL

/*
 * NO_CLOCK        	// STOP
 * NO_PRESCALLER
 * CLK_8
 * CLK_64
 * CLK_256
 * CLK_1024
 * COUNTER_Falling_edge			// External clock source on T0 pin. Clock on falling edge.
 * COUNTER_Rising_edge			// External clock source on T0 pin. Clock on rising edge.
 */
#define Timer0_prescaler CLK_1024


/*
 * NO_INTERRUPT
 * NORMAL
 * CTC
 */
#define TIMER0_INTERRUPT	NORMAL




/***********************************************TIMER2********************************/

/*	NORMAL
 * 	CTC
 * 	PWM_PHASE_CORRECT
 * 	FAST_PWM
 */
#define  Timer2_Mode NORMAL

/*
 * NO_CLOCK        	// STOP
 * NO_PRESCALLER
 * CLK_8
 * CLK_32
 * CLK_64
 * CLK_128
 * CLK_256
 * CLK_1024
 */
#define Timer2_prescaler CLK_1024


/*
 * NO_INTERRUPT
 * NORMAL
 * CTC
 */
#define TIMER2_INTERRUPT	NO_INTERRUPT

#endif
