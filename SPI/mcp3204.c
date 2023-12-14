                        /*  file: mcp3204.c */
#include <LPC21xx.h>
#include "types.h"
#include "spi_defines.h"
#include "defines.h"
#include "spi.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_defines.h"

u32 adcVal;
f32 aR;

void clocking(void)
{
	SCLRBIT(IOCLR0,CLK);
	delay_us(1);
  SSETBIT(IOSET0,CLK);
	delay_us(1);	
}

f32 Read1_ADC_MCP3204(u8 chNo)
{
	s32 i;
  //u32 adcVal;
  //f32 aR;
		
	IOSET0|=1<<CS|1<<DIN|1<<DOUT|1<<CLK;
  IODIR0|=1<<CS|1<<DIN|1<<CLK;	
	
  IOCLR0=1<<CS;  //select/activate chip 
	//1st clocking  to send start bit '1' 
	clocking();
	
  //2nd clocking to  send single-ended mode of conversion bit '1' 
	clocking();
	
 	//3rd clocking to  send D2 don't care bit 
	clocking();
	
	//4th clocking to send D1 Channel Selection Bit
	WRITEBIT(IOPIN0,DIN,(chNo>>1)&1); 
	clocking();
	
	//5th clocking D0 Channel Selection Bit & Start Sampling
  WRITEBIT(IOPIN0,DIN,(chNo&1)); 
	clocking();
	
	//6th clocking for Continue & Ending Sampling
  clocking();
	
	//7th clocking For Slave to Issue NULL Bit
  clocking();
	//while(READBIT(IOPIN0,DOUT)!=0);
	
	//12 clockings for converting & reading & storing 12-bit digital data
	//msb to lsb order
	for(i=11;i>=0;i--)
	{
	  clocking();
	  READBIT(IOPIN0,DOUT) ? (adcVal|=1<<i) : (adcVal&=~(1<<i)); 	   		
	}
	
	//de-select/de-activate chp
	IOSET0=1<<CS;

  aR=((adcVal*3.3)/4096); 
	return aR;
}
                     /* end of mcp3204.c */
