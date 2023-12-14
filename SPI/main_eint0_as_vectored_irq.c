											/*eint0_as_vectored_irq.c */
#include <LPC21xx.h> 
#include "types.h"
#include "defines.h"
#include "pin_function_defines.h"

// external_interrupt_defines start 
							
#define LEVEL                 0
#define EDGE                  1
#define FALL_EDGE             0
#define RISE_EDGE             1

#define FIQ                   0
#define IRQ                   1
#define NON_VECTORED_IRQ      2

#define EINT0_TRIG_LEVEL      EDGE
#define EINT0_TRIG_EDGE_TYPE  FALL_EDGE
#define EINT0_INT_TYPE        NON_VECTORED_IRQ
#define EINT0_CHNO            14
#define EINT0_FLAG            0x01

#define EINT0_STATUS_LED      7

//external_interrupt_defines end 

//EINT0 ISR Definitions
#if (EINT0_INT_TYPE == IRQ)
void eint0_isr(void) __irq
#endif	
#if	(EINT0_INT_TYPE == NON_VECTORED_IRQ)
void eint0_isr(void) __irq
#endif	
#if (EINT0_INT_TYPE == FIQ)
void FIQ_Handler (void)	 __irq
#endif	
{
	 //start of user isr response
   CPLBIT(IOPIN0,EINT0_STATUS_LED);  
	 //end of user isr response
   EXTINT = EINT0_FLAG;	//Clear EINT0 flag
   VICVectAddr = 0x00; //Dummy write to clear register 
}

void Enable_EINT0_Interrupt()
{
	#if EINT0_TRIG_LEVEL == EDGE
	EXTMODE  = 0x01;	//select edge triggering
	#endif
	
	#if EINT0_TRIG_EDGE_TYPE == RISE_EDGE
  EXTPOLAR  = 0x01;	//select falling edge
	#endif
	
  EXTINT = EINT0_FLAG;	// clear EINT0 flag
	

	// configuring VIC for Vectored IRQ EINT0
	//Enable EINT0 in the VIC
 	VICIntEnable = 1<<EINT0_CHNO;

	#if ((EINT0_INT_TYPE==IRQ) || (EINT0_INT_TYPE==NON_VECTORED_IRQ)) 	
  #endif
 	// Int Type ALL  IRQ's default
  // VICIntSelect = 0; 
  #if EINT0_INT_TYPE==FIQ
  // configuring VIC for EINT0 as FIQ 
 		   VICIntSelect |= 1<<ENT0_CHN0;
  #endif

  
  #if (EINT0_INT_TYPE==IRQ) 	
 	//Enable VICVectAddr0 reg to store EINT0 ISR Addr 
  VICVectCntl0 = 0x20|EINT0_CHNO;	 
  VICVectAddr0 = (unsigned )eint0_isr;
  #endif
	
	#if (EINT0_INT_TYPE==NON_VECTORED_IRQ) 	
 	//Enable VICVectAddr0 reg to store EINT0 ISR Addr
  VICDefVectAddr = (unsigned )eint0_isr;
  #endif
	
}

u32 counter;

int  main(void)
{
   CFGPIN(PINSEL0,1,EINT0_0_1);
	 SETBIT(IODIR0,EINT0_STATUS_LED);
   Enable_EINT0_Interrupt(); 	
   while(1)
   {
     counter++;
   }					

}

