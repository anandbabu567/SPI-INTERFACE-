#include <LPC21xx.H>

// Defines for output device 
//which gets affected upon ext interrupt fire
#define LED1 1<<24

//function invoked in ISR
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

//Vectored ISR Definition
void VectoredIRQ (void)	 __irq
{
    Toggle_LED(LED1);
	EXTINT = 0x01; //Clear the peripheral interrupt flag
	VICVectAddr 	= 0; //Dummy write to signal end of interrupt
}

void FIQ_Handler (void)	 __irq
{
    Toggle_LED(LED1);
	EXTINT = 0x01; //Clear the peripheral interrupt flag
	VICVectAddr 	= 0; //Dummy write to signal end of interrupt
}

	  //Sytem Initialization Definitions as per requirement
void Init_Sys()
{
   PINSEL1 = 0x00000001;

   IODIR0=LED1;
      
   EXTMODE = 0x01;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT = 0x01;	//clear EINT0 flag initially   


   //configuring VIC for Vectored & Non interrupt 

   //default
   VICIntSelect = 1<<14; // Int Type ALL IRQ but one FIQ's 
   VICIntEnable	= 1<<14;
   VICVectCntl0 = 0x20|14;	 // EINT0 P0.16
   //pass the address of the Non Vec IRQ into the VIC slot
   VICVectAddr0 = (unsigned)VectoredIRQ; 
  
   //Enable EXTINT0 in the VIC
  
}

unsigned int counter;

int main (void)
{
  	Init_Sys();
	while(1)
	{
	  counter++;													//Idle loop
	}

}

