                            /* lcd_arduino_api.c */                  
#include <LPC21xx.h>
#include "types.h"
#include "lcd_defines.h"
#include "delay.h"
#include "arduino_api.h"

void WriteLCD(u8 dat)
{
	u32 i;
	digitalWrite(LCD_RW,0); //cfg for writing to LCD
	
	for(i=0;i<=7;i++)
	   digitalWrite(i+LCD_D0,((dat>>i)&1));
	
	digitalWrite(LCD_EN,1); //high to...
	delay_us(1);
	digitalWrite(LCD_EN,0); //low pulse
	delay_ms(2);  //atleast 2ms between consecutive writes
	              //for syn bt/w cpu & LCD
}

void CmdLCD(u8 cmd)
{
	digitalWrite(LCD_RS,0);//select command register for writing to
	WriteLCD(cmd);//write to command register
}

void CharLCD(u8 ch)
{
	digitalWrite(LCD_RS,1); //select data register for writing to
	WriteLCD(ch);  //write to data register then to DDRAM 
	               //for display
}	

void InitLCD(void)
{
	u32 i;
	for(i=0;i<=10;i++)
	   pinMode(i+LCD_D0,GPIO_OUT);
	
	delay_ms(15);
	delay_us(100);
	CmdLCD(0x30);
	delay_ms(4);
	delay_us(200);
	CmdLCD(0x30);
	delay_us(200);
	CmdLCD(0x30);
	CmdLCD(0x38);
	CmdLCD(0x08);
	CmdLCD(0x01);
	CmdLCD(0x06);
	CmdLCD(DSP_ON_CUR_OFF);
}	

void StrLCD(u8 *ptr) 
{
  while(*ptr)	
      CharLCD(*ptr++); 
}

void U32LCD(u32 n)
{
	u8 a[10]={0};	
	s16 i=0;
	
	if(n==0)
		CharLCD('0');
	else
	{
		while(n>0)
		{	
		 a[i]=(n%10)+48;
		 n=n/10;
		 i++;
		}
    for(--i;i>=0;i--)
        CharLCD(a[i]);		
  }		
}

void F32LCD(float f,u8 ndp)
{
	u32 i; s8 j;

	if(f<0.0)
	{	
		CharLCD('-');
		f=-f;
	}
	i=f;
	U32LCD(i);
	CharLCD('.');
	for(j=0;j<ndp;j++)
	{
		f=(f-i)*10;
		i=f;
		CharLCD(i+48);
	}
}

void S32LCD(s32 n)
{
	if(n<0)
	  CharLCD('-');
  n=-n;
  U32LCD(n);	
}

void BuildCGRAM(u8 *p,u8 n)
{
	u8 i;
	//point cursor to CGRAM beginning
	CmdLCD(GOTO_CGRAM_START);
	for(i=0;i<n;i++)
	{
		//write cgram via data register
		CharLCD(p[i]);
	}
	//point back cursor to DDRAM
	CmdLCD(GOTO_LINE1_POS0);
}
