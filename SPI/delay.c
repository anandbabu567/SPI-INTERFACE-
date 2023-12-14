#include "types.h"

void delay_us(u32 dlyUS)
{
	u32 i;
	for(;dlyUS;dlyUS--)
	    for(i=8;i>0;i--);
}

void delay_ms(u32 dlyMS)
{
	u32 i;
	for(;dlyMS;dlyMS--)
	  for(i=12000;i>0;i--);  
}
