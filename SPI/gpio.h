                     /* gpio.h */   
#include "types.h"

void CfgPortPin(u32 portNo,u32 pinNo,u32 pinFunc);
void SetPortPin(u32 portNo,u32 pinNo);
void ClrPortPin(u32 portNo,u32 pinNo);
void Wr2PortPin(u32 portNo,u32 pinNo,u32 bit);
u32 RdPortPin(u32 portNo,u32 pinNo);
//add more declarations
