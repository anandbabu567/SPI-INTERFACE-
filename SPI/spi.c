                               /* spi.c */
#include <LPC214x.h>
#include "types.h"
#include "spi_defines.h"
#include "defines.h"
#include "delay.h"

u8 spi(u8 sDat)
{
   u8 rDat;
	 s32 i; 
	 for(i=7;i>=0;i--)
	 {
		 CLRBIT(IOPIN0,CLK);
		 delay_us(1);
		 READBIT(IOPIN0,DOUT) ? SETBIT(rDat,i) : CLRBIT(rDat,i);
  	 WRITEBIT(IOPIN0,DIN,(sDat>>i)&1);
		 SETBIT(IOPIN0,CLK);
		 delay_us(1);
	 }	  
}
				/* end of spi.c */

