                             /* lm35.c */
#include "types.h"
#include "mcp3204.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "mcp3204_defines.h"
//f32 aR1,aR2,aRDiff,tDegC;
	
f32 Read_Temperature(void)
{
	#if READ1_ADC_MCP3204_ENABLE > 0
	return (Read1_ADC_MCP3204(0) * 100);
	#endif
	
	#if READ2_ADC_MCP3204_ENABLE > 0
	return (Read2_ADC_MCP3204(0) * 100);
	#endif
	
}

f32 Read_Temperature_NP(void)
{
  f32 aR1,aR2,aRDiff,tDegC;
	
	#if READ1_ADC_MCP3204_ENABLE > 0
	aR1= Read1_ADC_MCP3204(0);
	aR2= Read1_ADC_MCP3204(1);
	#endif
	
	#if READ2_ADC_MCP3204_ENABLE > 0
	aR1= Read2_ADC_MCP3204(0);
	aR2= Read2_ADC_MCP3204(1);
	#endif
	
	aRDiff=aR1-aR2;
	tDegC=aRDiff*100;
	return tDegC;
}
