#include <LPC21xx.H>

// Defines for output device 
//which gets affected upon ext interrupt fire
#define LED1 1<<0

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

//Non-Vectored ISR Definition
void NonVectoredIRQ (void)	 __irq
{
    Toggle_LED(LED1);
	EXTINT = 0x01; //Clear the peripheral interrupt flag
	VICVectAddr 	= 0; //Dummy write to signal end of interrupt
}

//Vectored ISR Definition
void VectoredIRQ (void)	 __irq
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
   VICIntSelect = 0; // Int Type ALL  IRQ's 

   VICVectCntl0 = 0x20|14;	 // EINT0 P0.16
   //pass the address of the Non Vec IRQ into the VIC slot
   VICVectAddr0 = (unsigned)VectoredIRQ; 
  
   //pass the address of the Non Vec IRQ into the VIC slot
   VICDefVectAddr = (unsigned)NonVectoredIRQ;	

   //Enable EXTINT0 in the VIC
   VICIntEnable	= 1<<14;
}

unsigned int counter;

int main (void)
{
  	Init_Sys();
	while(1)
	{
	  counter++;//Idle loop
	}

}

