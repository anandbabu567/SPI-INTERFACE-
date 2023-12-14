                       /* main_mcp3204_led_test.c */
#include <LPC21xx.h>
#include "types.h"
#include "mcp3204.h"
#include "delay.h"
#include "pin_function_defines.h"
#include "arduino_api.h"

#define rLED 32 //P1.16
#define gLED 33 //P1.17
#define bLED 34 //P1.18
#define yLED 35 //P1.19

main()
{
	f32 f;
	pinMode(rLED,GPIO_OUT);
	pinMode(gLED,GPIO_OUT);
	pinMode(bLED,GPIO_OUT);
	pinMode(yLED,GPIO_OUT);
	
  while(1)
  {
    f=Read_ADC_MCP3204(0);
		
	 	if(f<0.5)
		{
			digitalWrite(rLED,0);
			digitalWrite(gLED,0);
			digitalWrite(bLED,0);
			digitalWrite(yLED,0);
		}	
		if(f>=0.5 && f<1.0)
		{
			digitalWrite(rLED,1);
			digitalWrite(gLED,0);
			digitalWrite(bLED,0);
			digitalWrite(yLED,0);
		}
    else if((f>=1.0) && (f<2.0))
		{ 
			digitalWrite(rLED,0);
			digitalWrite(gLED,1);
			digitalWrite(bLED,0);
			digitalWrite(yLED,0);
	 			
		}		
		else if((f>=2.0) && (f<3.0))
		{ 
	  	digitalWrite(rLED,0);
			digitalWrite(gLED,0);
			digitalWrite(bLED,1);
			digitalWrite(yLED,0);
	    }
		else if((f>=3.0) && (f<3.3)) 
		{ 
			digitalWrite(rLED,0);
			digitalWrite(gLED,0);
			digitalWrite(bLED,0);
			digitalWrite(yLED,1);
	  }
		else if(f>=3.3)  
		{ 
			digitalWrite(rLED,1);
			digitalWrite(gLED,1);
			digitalWrite(bLED,1);
			digitalWrite(yLED,1);
	    }
		delay_ms(100);
  }
}
					/* end of main.c */
