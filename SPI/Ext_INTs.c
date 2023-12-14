  			/*Vectored Interrupt Demonstration */
#include <LPC21xx.h> 

#define LED1 (1<<22) /* P0.22 LED1 */
#define	LED2 (1<<23) /* P0.23 LED2 */
#define LED3 (1<<24) /* P0.24 LED3 */ 	
#define LED4 (1<<25) /* P0.25 LED4 */

// EINT0 - P0.16
// EINT1 - P0.14
// EINT2 - P0.15
// EINT3 - P0.20

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

//void __irq FIQ_Handler(void)

//vectored ISR Definitions
void __irq IRQ_Eint0(void)
{  
   Toggle_LED(LED1);
   EXTINT = 0x01;	//Clear EINT0 flag
   VICVectAddr = 0x00;   
}
	
void   __irq IRQ_Eint1(void)
{  
   Toggle_LED(LED2);
   EXTINT = 0x02;	//Clear EINT1 flag
   VICVectAddr = 0x00;   
}
		
void   __irq IRQ_Eint2(void)
{  
   Toggle_LED(LED3);
   EXTINT = 0x04;	//Clear EINT2 flag
   VICVectAddr = 0x00;   
}
		
void   __irq IRQ_Eint3(void)
{
   Toggle_LED(LED4);  
   EXTINT = 0x08;		// Clear EINT3
   VICVectAddr = 0x00;
}


unsigned int counter=0;

int  main(void)
{ 
   PINSEL0 = 0xA0000000;
   PINSEL1 = 0x00000301;

   IO0DIR = LED1|LED4|LED2|LED3;

   //configuring Ext INT logic peripheral
   EXTMODE = 0x0F;	//select edge triggering	
   EXTPOLAR = 0x00;	//select falling edge	
   EXTINT = 0x0F;	// clear EINT0-EINT3 flags initially

   // configuring VIC for Vectored Ext INTs EINT0¡EINT3 
   VICIntSelect = 0; // Int Type ALL  IRQ's 
   VICIntEnable = (1<<14)|(1<<15)|(1<<16)|(1<<17);	// EINT0¡¢EINT3

   VICVectCntl10 = 0x20|14;	      // EINT0 P0.16
   VICVectAddr10 = (unsigned )IRQ_Eint0; 
  // VICVectAddr0 = (int)FIQ_Handler; 

   VICVectCntl1 = 0x20|15;		 // EINT1 P0.14
   VICVectAddr1 = (unsigned )IRQ_Eint1; 	

   VICVectCntl2 = 0x20|16;		 // EINT2 P0.15
   VICVectAddr2 = (unsigned )IRQ_Eint2; 	
   	
   VICVectCntl3 = 0x20|17;		 //EINT3  P0.20
   VICVectAddr3 = (unsigned )IRQ_Eint3; 	
   
   //Enable Ext INTs in VIC   
  


   while(1)
   {
     counter++;
   }					

}

