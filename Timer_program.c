/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 6 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

void Timer0_Init()
{
#if Timer0_Mode == NORMAL
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

#elif Timer0_Mode == PWM_PHASE_CORRECT
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

#elif Timer0_Mode == CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#elif Timer0_Mode == FAST_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#else
			#error("You chose Wrong clock type")
#endif


#if Timer0_prescaler == NO_CLOCK
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
#elif Timer0_prescaler == NO_PRESCALLER
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
#elif Timer0_prescaler == CLK_8
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
#elif Timer0_prescaler == CLK_64
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
#elif Timer0_prescaler == CLK_256
		CLR_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
#elif Timer0_prescaler == CLK_1024
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
#elif Timer0_prescaler == COUNTER_Falling_edge
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
#elif Timer0_prescaler == COUNTER_Rising_edge
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
#else
			#error("You chose Wrong clock type")
#endif


#if TIMER0_INTERRUPT ==	NO_INTERRUPT
		CLR_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);

#elif TIMER0_INTERRUPT == NORMAL
		SET_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);

#elif TIMER0_INTERRUPT == CTC
		CLR_BIT(TIMSK,0);
		SET_BIT(TIMSK,1);

#else
			#error("You chose Wrong clock type")
#endif



}

uint8_t Timer0_GetValue(uint8_t *getvalue)
{
	*getvalue = TCNT0;
	return TCNT0;
}

void Timer0_Stop()
{
			CLR_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
}

void Timer0_SetCTC(uint8_t CompareValue)
{
	OCR0 = CompareValue;
}

void Timer0_SetovfFlag(void)
{
	SET_BIT(TIFR,0);
}

void Timer0_CheckovfFlag(uint8_t *OverflowFlag)
{
	*OverflowFlag = GET_BIT(TIFR,0);
}

void Timer0_SetCTCFlag(void)
{
	SET_BIT(TIFR,1);
}


void Timer0_CheckCTCFlag(uint8_t *OverflowFlag)
{
	*OverflowFlag = GET_BIT(TIFR,1);
}


void Timer0_Start(uint8_t InitalTick)
{
	TCNT0 = InitalTick;
}


void Timer0_SetBusyWait(uint16_t Ticks)
{
	uint8_t Overflow_Number = Ticks / Timer0_OVF;
	uint8_t inital_Tick_value = Timer0_OVF - (Ticks % Timer0_OVF);
	uint8_t ovf_flag=0;
	uint8_t i;
	Timer0_Start(inital_Tick_value);
	for(i=0;i<=Overflow_Number;i++)
			 {
				 Timer0_CheckovfFlag(&ovf_flag);
				 while(ovf_flag==0)
				 {
					 Timer0_CheckovfFlag(&ovf_flag);
				 }
				 Timer0_SetovfFlag();
			 }
}


void Timer0_OvfISR(void (*Callback)(void))
{
	Timer0_ovfCallback = Callback;
}


/* Timer0 Overflow ISR*/
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	Timer0_ovfCallback();
}



void Timer0_CTCISR(void (*Callback)(void))
{
	Timer0_CTCCallback = Callback;
}


/* Timer0 CTC ISR*/
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	Timer0_CTCCallback();
}



/*********************************************************************************************/
/* TIMER 2
 *
 **********************************************************************************************/

void Timer2_Init()
{
#if Timer2_Mode == NORMAL
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);

#elif Timer2_Mode == PWM_PHASE_CORRECT
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

#elif Timer2_Mode == CTC
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#elif Timer2_Mode == FAST_PWM
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
#else
			#error("You chose Wrong clock type")
#endif


#if Timer2_prescaler == NO_CLOCK
		CLR_BIT(TCCR2,0);
		CLR_BIT(TCCR2,1);
		CLR_BIT(TCCR2,2);
#elif Timer2_prescaler == NO_PRESCALLER
		SET_BIT(TCCR2,0);
		CLR_BIT(TCCR2,1);
		CLR_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_8
		CLR_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		CLR_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_32
		SET_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		CLR_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_64
		CLR_BIT(TCCR2,0);
		CLR_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_128
		SET_BIT(TCCR2,0);
		CLR_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_256
		CLR_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
#elif Timer2_prescaler == CLK_1024
		SET_BIT(TCCR2,0);
		SET_BIT(TCCR2,1);
		SET_BIT(TCCR2,2);
#else
			#error("You chose Wrong clock type")
#endif


#if TIMER2_INTERRUPT ==	NO_INTERRUPT
		CLR_BIT(TIMSK,6);
		CLR_BIT(TIMSK,7);

#elif TIMER2_INTERRUPT == NORMAL
		SET_BIT(TIMSK,6);
		CLR_BIT(TIMSK,7);

#elif TIMER2_INTERRUPT == CTC
		CLR_BIT(TIMSK,6);
		SET_BIT(TIMSK,7);

#else
			#error("You chose Wrong clock type")
#endif


}


uint8_t Timer2_GetValue(uint8_t *getvalue)
{
	*getvalue = TCNT2;
	return TCNT2;
}


void Timer2_Stop()
{
			CLR_BIT(TCCR2,0);
			CLR_BIT(TCCR2,1);
			CLR_BIT(TCCR2,2);
}

void Timer2_SetCTC(uint8_t CompareValue)
{
	OCR2 = CompareValue;
}

void Timer2_SetovfFlag(void)
{
	SET_BIT(TIFR,6);
}


void Timer2_CheckovfFlag(uint8_t *OverflowFlag)
{
	*OverflowFlag = GET_BIT(TIFR,6);
}

void Timer2_SetCTCFlag(void)
{
	SET_BIT(TIFR,7);
}

void Timer2_CheckCTCFlag(uint8_t *OverflowFlag)
{
	*OverflowFlag = GET_BIT(TIFR,7);
}


void Timer2_Start(uint8_t InitalTick)
{
	TCNT2 = InitalTick;
}


void Timer2_SetBusyWait(uint16_t Ticks)
{
	uint8_t Overflow_Number = Ticks / Timer2_OVF;
	uint8_t inital_Tick_value = Timer2_OVF - (Ticks % Timer2_OVF);
	uint8_t ovf_flag=0;
	uint8_t i;
	Timer2_Start(inital_Tick_value);
	for(i=0;i<=Overflow_Number;i++)
			 {
				 Timer2_CheckovfFlag(&ovf_flag);
				 while(ovf_flag==0)
				 {
					 Timer2_CheckovfFlag(&ovf_flag);
				 }
				 Timer2_SetovfFlag();
			 }
}



void Timer2_OvfISR(void (*Timer2_Callback)(void))
{
	Timer2_ovfCallback = Timer2_Callback;
}

/* Timer0 Overflow ISR*/
void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	Timer2_ovfCallback();
}



void Timer2_CTCISR(void (*Timer2_Callback)(void))
{
	Timer2_CTCCallback = Timer2_Callback;
}


/* Timer0 CTC ISR*/
void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	Timer2_CTCCallback();
}



