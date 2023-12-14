                            /* lcd_defines.h */
#ifndef __LCD_DEFINES_H__
#define __LCD_DEFINES_H__

#define CLEAR_LCD            0x01
#define RET_CUR_HOME         0x02
#define SHIFT_CUR_FW         0x06
#define DSP_ON_CUR_OFF       0x0c
#define DSP_ON_CUR_ON        0x0E
#define DSP_ON_CUR_BLINK     0x0F
#define MODE_8BIT_1LINE      0x30
#define MODE_4BIT_1LINE      0x20
#define MODE_8BIT_2LINE      0x38
#define MODE_4BIT_2LINE      0x28
#define GOTO_LINE1_POS0      0x80
#define GOTO_LINE2_POS0      0xC0
#define GOTO_LINE3_POS0      0x94
#define GOTO_LINE4_POS0      0xD4
#define GOTO_CGRAM_START     0x40
#define SHIFT_CUR_LEFT       0x10
#define SHIFT_CUR_RIGHT      0x14


#define LCD_D0 8//p0.8
#define LCD_D1 9 
#define LCD_D2 10
#define LCD_D3 11
#define LCD_D4 12
#define LCD_D5 13
#define LCD_D6 14
#define LCD_D7 15

#define LCD_RS 16
#define LCD_RW 17
#define LCD_EN 18 //p0.18

#endif
