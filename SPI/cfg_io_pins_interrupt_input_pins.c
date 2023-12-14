											/*cfg_io_pins_interrupt_input_pins.c */
#include <LPC21xx.h> 
#include "defines.h"
#include "pin_function_defines.h"
#include "types.h"

int  main(void)
{
  //cfg p0.1 as EINT0 input pin
	CFGPIN(PINSEL0,1,EINT0_0_1);
	//cfg p0.3 as EINT1 input pin
	CFGPIN(PINSEL0,3,EINT1_0_3);
	//cfg p0.7 as EINT2 input pin
	CFGPIN(PINSEL0,7,EINT2_0_7);
	//cfg p0.9 as EINT3 input pin
	CFGPIN(PINSEL0,9,EINT3_0_9);
	
	//cfg p0.16 as EINT0 input pin
	CFGPIN(PINSEL1,(16-16),EINT0_0_16);
	//cfg p0.14 as EINT1 input pin
	CFGPIN(PINSEL0,14,EINT1_0_14);
	//cfg p0.15 as EINT2 input pin
	CFGPIN(PINSEL0,15,EINT2_0_15);
	//cfg p0.20 as EINT3 input pin
	CFGPIN(PINSEL1,(20-16),EINT3_0_20);
	
	//cfg p0.30 as EINT3 input pin
	CFGPIN(PINSEL1,(30-16),EINT3_0_30);
}

