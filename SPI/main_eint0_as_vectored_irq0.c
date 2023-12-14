											/*main_eint0_as_vectored_irq.c */
#include <LPC21xx.h> 
#include "pin_function_defines.h"
#include "types.h"
#include "arduino_api.h"
#include "defines.h"
#include "external_interrupts.h"

#define LED 8   //led at p0.8 pin


u32 counter=0;

int  main(void)
{
	//cfg p0.8 pin as gpio output pin
	pinMode(7,GPIO_OUT);
	//cfg p0.1 as EINT0 input pin
	pinMode(1,EINT0_0_1);
	Enable_EINT0_Interrupt();
	while(1)
  {
     counter++;
  }					

}

