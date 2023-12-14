#define LED1 (1<<22)  /* P0.22 LED1 */
#define	LED2 (1<<23)	 /* P0.23 LED2 */
#define LED3 (1<<24)	 /* P0.24 LED3 */ 	
#define LED4 (1<<25)  /* P0.25 LED4 */

// EINT0 - P0.16
// EINT1 - P0.14
// EINT2 - P0.15
// EINT3 - P0.20
void Toggle_LED(unsigned int LED)
{
   
   IO0SET;						
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
