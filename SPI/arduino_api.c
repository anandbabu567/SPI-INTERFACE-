                             /* arduino_api.c */
#include "types.h"
#include "pin_function_defines.h"
#include "gpio.h"

void pinMode(u32 pinNo,u32 pinFunc)
{
	if(pinNo<32)
	{
		CfgPortPin(0,pinNo,pinFunc);
	}
	else if((pinNo>=32)&&(pinNo<48))
	{
		CfgPortPin(1,(pinNo-16),pinFunc);
	}
}

void digitalWrite(u32 pinNo,u32 bit)
{
	if(pinNo<32)
	{
	  Wr2PortPin(0,pinNo,bit);	
	}
	else if((pinNo>=32)&&(pinNo<48))
	{
	  Wr2PortPin(1,(pinNo-16),bit);
	}
}

u32  digitalRead(u32 pinNo)
{
	u32 t;
	if(pinNo<32)
	{
	  t=RdPortPin(0,pinNo);	
	}
	else if((pinNo>=32)&&(pinNo<48))
	{
	  t=RdPortPin(1,(pinNo-16));
	}
	return t;
}
