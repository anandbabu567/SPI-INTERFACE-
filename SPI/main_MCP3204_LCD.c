                    /* main.c */
#include <LPC21xx.h>
#include "types.h"
#include "mcp3204.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"
//extern  u32 adcVal;
extern  f32 aR;
main()
{
	//f32 f;
	InitLCD();
  while(1)
  {
    Read_ADC_MCP3204(0);
    //CmdLCD(GOTO_LINE1_POS0);
		//U32LCD(adcVal);
		CmdLCD(GOTO_LINE1_POS0+8);
		F32LCD(aR,3);
		delay_ms(100);
		CmdLCD(CLEAR_LCD);
  }
}
					/* end of main.c */
