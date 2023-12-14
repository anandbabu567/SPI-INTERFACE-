											/*main_eint0_interrupt.c */
#include <LPC21xx.h> 
#include "types.h"
#include "defines.h"
#include "delay.h"

#include "external_interrupt_defines.h"
#include "external_interrupts.h"
#include "arduino_api.h"

#include "pin_function_defines.h"
#include "arduino_api.h"
#include "lcd_defines.h"
#include "lcd.h"

//u32 counter;

int  main(void)
{
	 InitLCD();
   CFGPIN(PINSEL0,1,EINT0_0_1);
	 SETBIT(IODIR0,EINT0_STATUS_LED);
   Enable_EINT0_Interrupt(); 	
   while(1)
   {
     StrLCD("HELLO");
		 CmdLCD(GOTO_LINE1_POS0);
		 delay_ms(100);
		 CmdLCD(0x01);
   }					
}

