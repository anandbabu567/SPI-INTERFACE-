/************************************************************/
/* Example: configuration of VIC for nonvectored interrupt   */
/* Demonstrates serving the external interrupts as a non	*/ 
/* vectored interrupt										*/
/* Oscillator frequency 12.000 Mhz							*/
/************************************************************/

#include <LPC21xx.H>

#define LED1 1<<0
#define LED2 1<<1
#define LED3 1<<2
#define LED4 1<<3

void Toggle_LED(unsigned int LED)
{
  if((IOPIN0 & (LED))==0)
  {
   IOSET0=LED;
  }
  else
  {  
   IOCLR0=LED;
  }
}

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


unsigned int counter;
int main (void)
{
   PINSEL0 = 0xA0000000;
   PINSEL1 = 0x00000301;

   IODIR0=LED1|LED2|LED3|LED4;
      
   EXTMODE = 0x0F;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT = 0x0F;	//clear EINT0-EINT3 flag initially   

   //pass the address of the IRQ into the VIC slot
   VICDefVectAddr = (unsigned)NonVectoredIRQ;	

   //Enable EXTINT0 in the VIC
   VICIntEnable	= 1<<14|1<<15|1<<16|1<<17;

	while(1)
	{
	  counter++;													//Idle loop
	}

}

