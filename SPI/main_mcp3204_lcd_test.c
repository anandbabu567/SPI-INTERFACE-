                       /* main_mcp3204_lcd_test.c */
#include <LPC21xx.h>
#include "types.h"
#include "mcp3204.h"
#include "delay.h"
#include "pin_function_defines.h"
#include "arduino_api.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "mcp3204.h"

int main()
{
	f32 f;
  InitLCD();
	StrLCD("mcp3204 test");
	delay_ms(100);
	
  while(1)
	{
		CmdLCD(GOTO_LINE2_POS0);
    f=Read1_ADC_MCP3204(0);
    F32LCD(f,3);
		delay_ms(100);
  	CmdLCD(GOTO_LINE2_POS0);
 		StrLCD("                ");
		
	}
}
					/* end of main.c */
