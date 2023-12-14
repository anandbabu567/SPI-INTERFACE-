                   /* External_Interrupts. */
									 
#include "types.h"
#include <LPC21xx.h>
#include "defines.h"
#include "external_interrupt_defines.h"
#include "delay.h"
#include "pin_function_defines.h"
#include "arduino_api.h"
#include "lcd_defines.h"
#include "lcd.h"

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
	CmdLCD(0x01);
	CmdLCD(GOTO_LINE1_POS0);
	StrLCD("BREAK PRESSED");
	delay_ms(1000);
	CmdLCD(0x01);
	CmdLCD(GOTO_LINE1_POS0);
	StrLCD("ENGINE TEMPARETURE");
	delay_ms(100);
	//CmdLCD(GOTO_LINE1_POS0);
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
  EXTPOLAR  = 0x01;	//select rising edge
	#endif
	
  EXTINT = EINT0_FLAG;	// clear EINT0 flag
	
	// configuring VIC for Vectored IRQ EINT0
	//Enable EINT0 in the VIC
 	VICIntEnable = 1<<EINT0_CHNO;

	// Int Type ALL  IRQ's default
  // VICIntSelect = 0; 
  #if EINT0_INT_TYPE==FIQ
  // configuring VIC for EINT0 as FIQ 
 		   VICIntSelect |= 1<<EINT0_CHNO;
  #endif
  
  #if (EINT0_INT_TYPE==IRQ) 	
 	//Enable VICVectAddr0 reg to store EINT0 ISR Addr 
  VICVectCntl0 = 0x20|EINT0_CHNO;	 
  VICVectAddr0 = (unsigned )eint0_isr;
  #endif
	
	#if (EINT0_INT_TYPE==NON_VECTORED_IRQ) 	
 	//Use VICDefVectAddr reg to store EINT0 ISR Addr
  VICDefVectAddr = (unsigned )eint0_isr;
  #endif
	
}
