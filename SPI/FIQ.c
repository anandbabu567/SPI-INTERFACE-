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

//FIQ ISR definition
void FIQ_Handler (void)	 __irq
{
    Toggle_LED(LED1);
	EXTINT = 0x01; //Clear the peripheral interrupt flag
}


unsigned int counter;

int main (void)
{
   PINSEL1 = 0x00000001;

   IODIR0=LED1;
      
   EXTMODE = 0x01;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT = 0x01;	//clear EINT0 flag initially   


   //configuring VIC for FIQ interrupt 

   //Enable EINT0 in the VIC
   VICIntEnable	= 1<<14;
    
   // EINT0 is on FIQ
   VICIntSelect = 1<<14; 
  
	while(1)
	{
	  counter++;													//Idle loop
	}

}

