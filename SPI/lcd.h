												/* lcd.h */
#ifndef __LCD_H__
#define __LCD_H__

#include"types.h"
void WriteLCD(u8);
void CmdLCD(u8);
void CharLCD(u8);
void InitLCD(void);
void StrLCD(u8 *);
void U32LCD(u32);
void S32LCD(s32);
void F32LCD(float,u8);
void BuildCGRAM(const u8 *,u8);

#endif
