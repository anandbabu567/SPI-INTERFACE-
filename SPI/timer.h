                                 /* timer.c */
								
#include "types.h"
void InitTimer0(void);
void tdelay_us(u32 microseconds); //Using Timer0
void tdelay_ms(u32 milliseconds); //Using Timer0
void tdelay_s(u32 seconds);       //Using Timer0
void Enable_Timer0_Interrupt(void);
