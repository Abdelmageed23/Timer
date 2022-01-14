/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 6 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/*								TIMER0                        */
void Timer0_Init();
uint8_t Timer0_GetValue(uint8_t *getvalue);
void Timer0_SetCTC(uint8_t CompareValue);
void Timer0_CheckovfFlag(uint8_t *OverflowFlag);
void Timer0_SetovfFlag(void);
void Timer0_CheckCTCFlag(uint8_t *OverflowFlag);
void Timer0_SetCTCFlag(void);
void Timer0_Start(uint8_t InitalTick);
void Timer0_Stop();
void Timer0_SetBusyWait(uint16_t Ticks);

void (*Timer0_ovfCallback)(void);
void Timer0_OvfISR(void (*Callback)(void));

void (*Timer0_CTCCallback)(void);
void Timer0_CTCISR(void (*Callback)(void));


/*************** TIMER2**************************************/


void Timer2_Init();
uint8_t Timer2_GetValue(uint8_t *getvalue);
void Timer2_SetCTC(uint8_t CompareValue);
void Timer2_SetovfFlag(void);
void Timer2_CheckovfFlag(uint8_t *OverflowFlag);
void Timer2_SetCTCFlag(void);
void Timer2_CheckCTCFlag(uint8_t *OverflowFlag);
void Timer2_Start(uint8_t InitalTick);
void Timer2_Stop();
void Timer2_SetBusyWait(uint16_t Ticks);


void (*Timer2_ovfCallback)(void);
void Timer2_OvfISR(void (*Timer2_Callback)(void));

void (*Timer2_CTCCallback)(void);
void Timer2_CTCISR(void (*Timer2_Callback)(void));


#endif
