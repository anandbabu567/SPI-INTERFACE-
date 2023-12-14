                           /* gpio.c */
#include "types.h"
#include "defines.h"
#include "pin_function_defines.h"
#include <LPC21xx.h>

void CfgPortPin(u32 portNo,u32 pinNo,u32 pinFunc)
{
	if(portNo==0)
	{
		if(pinFunc==GPIO_IN)
		{
			CLRBIT(IODIR0,pinNo);	
    }
    else if(pinFunc==GPIO_OUT)
    {
			SETBIT(IODIR0,pinNo);	
    }
		
    if((pinFunc==GPIO_IN)||(pinFunc==GPIO_OUT))
		   pinFunc=FUNC1;
		
		if(pinNo<=15)
		{
			CFGPIN(PINSEL0,pinNo,pinFunc);
		}
		else if((pinNo>=16)&&(pinNo<=31))
		{
			CFGPIN(PINSEL1,(pinNo-16),pinFunc);
		}
	}
	else if(portNo==1)
	{
		if(pinFunc==GPIO_IN)
		{
			CLRBIT(IODIR1,pinNo);
    }
    else if(pinFunc==GPIO_OUT)
    {
			SETBIT(IODIR1,pinNo);
    }				

    if((pinFunc==GPIO_IN)||(pinFunc==GPIO_OUT))
		   pinFunc=FUNC1;
			
		if((pinNo>=16)&&(pinNo<=31))
		{
			CFGPIN(PINSEL2,(pinNo-16),pinFunc);
		}		
	}
}	

void SetPortPin(u32 portNo,u32 pinNo)
{
	if(portNo==0)
	{
		SSETBIT(IOSET0,pinNo);
	}
	else if(portNo==1)
	{
		SSETBIT(IOSET1,pinNo);
	}
}	

void ClrPortPin(u32 portNo,u32 pinNo)
{
	if(portNo==0)
	{
		SSETBIT(IOCLR0,pinNo);
	}
	else if(portNo==1)
	{
		SSETBIT(IOCLR1,pinNo);
	}
}	

void TogglePortPin(u32 portNo,u32 pinNo)
{
	if(portNo==0)
	{
		CPLBIT(IOPIN0,pinNo);
	}
	else if(portNo==1)
	{
		CPLBIT(IOPIN1,pinNo);
	}
}

void Wr2PortPin(u32 portNo,u32 pinNo,u32 bit)
{
	if(portNo==0)
	{
		WRITEBIT(IOPIN0,pinNo,bit);
	}
	else if(portNo==1)
	{
		WRITEBIT(IOPIN1,pinNo,bit);
	}
}	

u32 RdPortPin(u32 portNo,u32 pinNo)
{
	u32 t;
	if(portNo==0)
	{
		t=READBIT(IOPIN0,pinNo);
	}
	else if(portNo==1)
	{
		t=READBIT(IOPIN1,pinNo);
	}
	return t;
}
