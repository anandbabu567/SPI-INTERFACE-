                        /* pin_function_defines.h */
#define FUNC1 0
#define FUNC2 1
#define FUNC3 2
#define FUNC4 3

#define CFGPIN(WORD,PIN,FUNC)  WORD=((WORD&~(0x00000003<<(PIN*2)))|(FUNC<<(PIN*2)))

#define GPIO_OUT 0xFFFFFFFF
#define GPIO_IN  0x00000000

//p0.0 pin functions
#define GPIO_0_0 FUNC1
#define TXD0_0_0 FUNC2
#define PWM1_0_0 FUNC3
#define RESV_0_0 FUNC4

//p0.1 pin functions
#define GPIO_0_1 FUNC1
#define EINT0_0_1 FUNC4

//p0.3 pin functions
#define GPIO_0_3  FUNC1
#define EINT1_0_3 FUNC4

//p0.7 pin functions
#define GPIO_0_7 FUNC1
#define EINT2_0_7 FUNC4

//p0.9 pin functions
#define GPIO_0_9 FUNC1
#define EINT3_0_9 FUNC4

//p0.14 pin functions
#define GPIO_0_14  FUNC1
#define EINT1_0_14 FUNC3

//p0.15 pin functions
#define GPIO_0_15  FUNC1
#define EINT2_0_15 FUNC3

//p0.16 pin functions
#define GPIO_0_16  FUNC1
#define EINT0_0_16 FUNC2


//p0.20 pin functions
#define GPIO_0_20 FUNC1
#define EINT3_0_20 FUNC4

//p0.30 pin functions
#define GPIO_0_30 FUNC1
#define EINT3_0_30 FUNC3

//add more defines for each of 46 i/o pins as applicable
