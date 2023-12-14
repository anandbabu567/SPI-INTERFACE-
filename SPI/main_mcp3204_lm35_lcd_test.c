                       /* main_mcp3204_lm35_lcd_test.c */
#include <LPC21xx.h>
#include "types.h"
#include "mcp3204.h"
#include "delay.h"
#include "pin_function_defines.h"
#include "arduino_api.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "external_interrupt_defines.h"
#include "external_interrupts.h"
#include "lm35.h"

/*
main()
{
	f32 f;
  InitLCD();
	CFGPIN(PINSEL0,1,EINT0_0_1);
	SETBIT(IODIR0,EINT0_STATUS_LED);
  Enable_EINT0_Interrupt(); 
StrLCD("LM35 test");
delay_ms(100);
	
  while(1)
	{
		CmdLCD(GOTO_LINE2_POS0);
    f=Read_Temperature_NP();
   F32LCD(f,2);
		delay_ms(10);
		
		CmdLCD(GOTO_LINE1_POS0);
		delay_ms(100);
		CmdLCD(0x01);
		CmdLCD(GOTO_LINE2_POS0);
   StrLCD("HELLO");
		 CmdLCD(GOTO_LINE1_POS0);
		 delay_ms(100);
		 CmdLCD(0x01);
		
	}
}
*/
main()
{
	f32 f;
  InitLCD();
	
	CFGPIN(PINSEL0,1,EINT0_0_1);
	SETBIT(IODIR0,EINT0_STATUS_LED);
  Enable_EINT0_Interrupt();
	StrLCD("ENGINE TEMPARETURE");
	delay_ms(100);
	
  while(1)
	{
		CmdLCD(GOTO_LINE2_POS0);
    f=Read_Temperature_NP();
    F32LCD(f,2);
		delay_ms(10);
		
	}
}
					/* end of main.c */
