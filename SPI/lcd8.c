                            /* lcd8.c */                  
#include <LPC21xx.h>
#include "types.h"
#include "defines.h"
#include "lcd_defines.h"
#include "delay.h"

void WriteLCD(u8 dat)
{
	IOCLR0=1<<LCD_RW; //cfg for writing to LCD
	WRITEBYTE(IOPIN0,LCD_D0,dat);
	IOSET0=1<<LCD_EN; //high to...
	delay_us(1);
	IOCLR0=1<<LCD_EN; //low pulse
	delay_ms(2);  //atleast 2ms between consecutive writes
	              //for syn bt/w cpu & LCD
}

void CmdLCD(u8 cmd)
{
	IOCLR0=1<<LCD_RS;//select command register for writing to
	WriteLCD(cmd);//write to command register
}

void CharLCD(u8 ch)
{
	IOSET0=1<<LCD_RS; //select data register for writing to
	WriteLCD(ch);  //write to data register then to DDRAM 
	               //for display
}	

void InitLCD(void)
{
	IODIR0|=((0xFF<<LCD_D0)|(1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN));
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
	CmdLCD(0x0e);
}	

void StrLCD(u8 *ptr) {	while(*ptr)	CharLCD(*ptr++); }

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
