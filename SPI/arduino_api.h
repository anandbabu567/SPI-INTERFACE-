                    /* arduino_api.h */
#include "types.h"
#include "pin_function_defines.h"

void pinMode(u32 pinNo,u32 pinFunc);
void digitalWrite(u32 pinNo,u32 bit);
u32  digitalRead(u32 pinNo);
