
#include <LPC21xx.H>

// Defines for output device 
//which gets affected upon ext interrupt fire
#define LED1 (1<<22) /* P0.22 LED1 */
#define	LED2 (1<<23) /* P0.23 LED2 */
#define LED3 (1<<24) /* P0.24 LED3 */ 	
#define LED4 (1<<25) /* P0.25 LED4 */

/* pins from which ext interrupts are fired 
 EINT0 - P0.16
 EINT1 - P0.14
 EINT2 - P0.15
 EINT3 - P0.20
*/
	//function invoked in ISR
void Toggle_LED(unsigned int LED)
{
   if((IOSET0&LED)==0)				
   {  
    IO0SET = LED;
   }
   else
   {  
    IO0CLR = LED;
   }
}

	//Non-Vectored ISR Definition
void NonVectoredIRQ (void)	 __irq
{
	if(VICIRQStatus&(1<<14))	//Test for the interrupt source
	{
	    Toggle_LED(LED1);
		EXTINT = 0x01; //Clear the peripheral interrupt flag
	}

	if(VICIRQStatus&(1<<15))	//Test for the interrupt source
	{
	    Toggle_LED(LED2);
		EXTINT = 0x02; //Clear the peripheral interrupt flag
	}

	if(VICIRQStatus&(1<<16))	//Test for the interrupt source
	{
	    Toggle_LED(LED3);
		EXTINT = 0x04; //Clear the peripheral interrupt flag
	}

	if(VICIRQStatus&(1<<17))	//Test for the interrupt source
	{
		Toggle_LED(LED4);
		EXTINT = 0x08; //Clear the peripheral interrupt flag
	}

	VICVectAddr 	= 0; //Dummy write to signal end of interrupt
}

	//Sytem Initialization Definitions as per requirement
void Select_Pins_Fun()
{
    PINSEL0 = 0xA0000000;
    PINSEL1 = 0x00000301;
}

void Config_GPIO_Dir()
{
   IO0DIR = LED1|LED4|LED2|LED3;
}   

void Config_ExtINTs()
{
  //configuring Ext INT logic peripheral
   EXTMODE = 0x0F;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT = 0x0F;	// clear EINT0-EINT3 flags initially
}

void Config_VIC()
{
   // Default 
   //VICIntSelect = 0; // Int Type ALL  IRQ's 

   //pass the address of the IRQ into the VIC slot
   VICDefVectAddr = (unsigned)NonVectoredIRQ;	

   //Enable Ext INTs in VIC   
   VICIntEnable = (1<<14)|(1<<15)|(1<<16)|(1<<17);	// EINT0¡¢EINT3
}

void Init_Sys()
{
  Select_Pins_Fun();
  Config_GPIO_Dir();
  Config_ExtINTs();
  Config_VIC();
}						 


// Main Application Begins Here
unsigned int counter;

int main (void)
{
   Init_Sys();

	while(1)
	{
	  counter++;													//Idle loop
	}

}

