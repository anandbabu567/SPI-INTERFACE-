                        /*  file: mcp3204_arduino_api.c */
#include "types.h"
#include "spi_defines.h"
#include "defines.h"
#include "arduino_api.h"
#include "spi.h"
#include "delay.h"
#include "mcp3204_defines.h"

u32 adcVal;
f32 aR;

#if READ1_ADC_MCP3204_ENABLE>0

void clocking(void)
{
	digitalWrite(CLK,0);
	delay_us(1);
  digitalWrite(CLK,1);
	delay_us(1);	
}	

f32 Read1_ADC_MCP3204(u8 chNo)
{
	s32 i;
  //u32 adcVal;
  //f32 aR;
		
	digitalWrite(CS,1);
	digitalWrite(DIN,1);
	digitalWrite(DOUT,1);
	digitalWrite(CLK,1);
  pinMode(CS,GPIO_OUT);
	pinMode(DIN,GPIO_OUT);
	pinMode(CLK,GPIO_OUT);	
	
  digitalWrite(CS,0);  //select/activate chip 
	//1st clocking  to send start bit '1' 
  clocking();
	
  //2nd clocking to  send single-ended mode of conversion bit '1' 
  clocking();
	
 	//3rd clocking to  send D2 don't care bit 
  clocking();
	
	//4th clocking to send D1 Channel Selection Bit
	digitalWrite(DIN,((chNo>>1)&1)); 
  clocking();
	
	//5th clocking D0 Channel Selection Bit & Start Sampling
	digitalWrite(DIN,(chNo&1)); 
  clocking();
	
	//6th clocking for Continue & Ending Sampling
  clocking();
	
	//7th clocking For Slave to Issue NULL Bit
  clocking();
	//while(READBIT(IOPIN0,DOUT)!=0);
	
	//12 clockings for converting,reading & storing 12-bit digital data
	//msb to lsb order
	for(i=11;i>=0;i--)
	{
    clocking();
    digitalRead(DOUT) ? (adcVal|=1<<i) : (adcVal&=~(1<<i)); 	   		
	}
	
	//de-select/de-activate chp
  digitalWrite(CS,1);

  aR=((adcVal*3.3)/4096); 
	return aR;
}
#endif

#if READ2_ADC_MCP3204_ENABLE > 0

f32 Read2_ADC_MCP3204(u8 chNo)
{
	u8 mByte,lByte;
	digitalWrite(CS,1);
	digitalWrite(DIN,1);
	digitalWrite(DOUT,1);
	digitalWrite(CLK,1);
  pinMode(CS,GPIO_OUT);
	pinMode(DIN,GPIO_OUT);
	pinMode(CLK,GPIO_OUT);	
	
  digitalWrite(CS,0);  //select/activate chip 
	spi(0x06);
	mByte=spi(chNo<<6);
	lByte=spi(0x00);
	digitalWrite(CS,1);  //deselect/deactivate chip 
	adcVal=((mByte&0x0f)<<8)|lByte;
	
	aR=((adcVal*3.3)/4096); 
	return aR;
}

#endif
                     /* end of mcp3204.c */
