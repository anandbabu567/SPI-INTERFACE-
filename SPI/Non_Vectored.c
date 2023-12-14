
#include <LPC21xx.H>

// Defines for output device 
//which gets affected upon ext interrupt fire
#define LED1 (1<<22) /* P0.22 LED1 */

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

	VICVectAddr 	= 0; //Dummy write to signal end of interrupt
}

unsigned int counter;

int main (void)
{

   PINSEL1 = 0x00000301;
   IO0DIR  = LED1;

	  //configuring Ext INT logic peripheral
   EXTMODE  = 0x01;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT   = 0x01;	// clear EINT0-EINT3 flags initially

   //Enable Ext INTs in VIC   
   VICIntEnable = (1<<14);

   //pass the address of the IRQ into the VIC slot
   VICDefVectAddr = (unsigned)NonVectoredIRQ;	

  
	while(1)
	{
	  counter++;													//Idle loop
	}

}

