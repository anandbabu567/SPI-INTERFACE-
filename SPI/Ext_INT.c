											/*main_eint0_as_vectored_irq.c */
#include <LPC21xx.h> 
#include "defines.h"

#define LED1 (1<<22) /* P0.22 LED1 */


//vectored ISR Definitions
void EINT0_ISR(void) __irq 
{  
   Toggle_LED(LED1);
   EXTINT = 0x01;	//Clear EINT0 flag
   VICVectAddr = 0x00; //Dummy write to clear register 
}
	

unsigned int counter=0;

int  main(void)
{ 
   PINSEL1 = 0x00000001;

   IO0DIR = LED1;

   //configuring External Interrupts peripheral
   EXTMODE  = 0x01;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT   = 0x01;	// clear EINT0 flags initially

   // configuring VIC for Vectored Ext INTs EINT0¡EINT3 
   // Int Type ALL  IRQ's 
   VICIntSelect = 0; 

   //Enable Ext INTs in VIC   
   VICIntEnable = (1<<14);	// EINT0 - enabling channel 14

//	 VICVectCntl0 = 0x20|14;	 // EINT0/P0.16
   VICVectAddr0 = (unsigned )IRQ_Eint0; 
   
  
   while(1)
   {
     counter++;
   }					

}

