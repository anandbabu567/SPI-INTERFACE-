                               /* spi_arduino_api.c */
#include "types.h"
#include "spi_defines.h"
#include "defines.h"
#include "delay.h"
#include "arduino_api.h"

u8 spi(u8 sDat)
{
   u8 rDat;
	 s32 i; 
	 for(i=7;i>=0;i--)
	 {
		 digitalWrite(CLK,0);
		 delay_us(1);
		 digitalRead(DOUT) ? SETBIT(rDat,i) : CLRBIT(rDat,i);
		 digitalWrite(DIN,((sDat>>i)&1));
		 digitalWrite(CLK,1);
		 delay_us(1);
	 }	  
	 return rDat;
}
				/* end of spi_arduino_api.c */

