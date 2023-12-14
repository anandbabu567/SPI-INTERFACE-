											/*cfg_io_pins_interrupt_input_pins.c */
#include <LPC21xx.h> 
#include "pin_function_defines.h"
#include "types.h"
#include "arduino_api.h"

int  main(void)
{
  //cfg p0.1 as EINT0 input pin
	 pinMode(1,EINT0_0_1);
	//cfg p0.3 as EINT1 input pin
   pinMode(3,EINT1_0_3);
	//cfg p0.7 as EINT2 input pin
	 pinMode(7,EINT2_0_7);
	//cfg p0.9 as EINT3 input pin
 	 pinMode(7,EINT2_0_7);

	//cfg p0.16 as EINT0 input pin
	pinMode(16,EINT0_0_16);
  //cfg p0.14 as EINT1 input pin
	pinMode(14,EINT1_0_14);
  //cfg p0.15 as EINT2 input pin
	pinMode(15,EINT2_0_15);
  //cfg p0.20 as EINT3 input pin
	pinMode(20,EINT3_0_20);
  
	//cfg p0.30 as EINT3 input pin
	pinMode(30,EINT3_0_30);
  
}

