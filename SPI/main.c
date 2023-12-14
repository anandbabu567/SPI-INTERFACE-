                    /* main.c */
#include <LPC21xx.h>
#include "types.h"
//#include "spi.h"
#include "mcp3204.h"

#define rLED 1<<16 //P0.16
#define gLED 1<<17 //P0.17
#define bLED 1<<18 //P0.18
#define yLED 1<<19 //P0.19

main()
{
	f32 f;
	IODIR1|=rLED|gLED|bLED|yLED;
	
  while(1)
  {
    f=Read_ADC_MCP3204(0);
		
	 	if(f<0.5)
		{
			IOCLR1=(rLED|gLED|bLED|yLED);
		}	
		if(f>=0.5 && f<1.0)
		{
			 IOSET1=rLED;
       IOCLR1=(gLED|bLED|yLED); 			
		}
    else if((f>=1.0) && (f<2.0))
		{ 
			 IOSET1=gLED;
       IOCLR1=(rLED|bLED|yLED); 			
		}		
		else if((f>=2.0) && (f<3.0))
		{ 
			 IOSET1=bLED;
       IOCLR1=(rLED|gLED|yLED); 			
    }
		else if((f>=3.0) && (f<4.0)) 
		{ 
			 IOSET1=yLED;
       IOCLR1=(rLED|gLED|bLED); 			
    }
		else if((f>=4.0) && (f<4.5)) 
		{ 
			IOPIN1|=(rLED|gLED|bLED|yLED);						
    }
  }
}
					/* end of main.c */
