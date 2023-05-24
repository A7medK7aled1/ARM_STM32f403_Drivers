#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_


#define STK_CTRL                *((volatile u32*)(0xE000E010))      /*Register to enables the SysTick features*/

#define COUNT_FLAG               16                                 /*Flag that rise when counter reach to zero ,CLR by reading it*/
#define CLK_SOURCE               2                                  /*Clock source selection bit*/
#define TICK_INT                 1                                  /*SysTick exception request enable*/
#define SYSTICK_ENABLE           0                                  /*Counter enable*/



#define STK_LOAD                *((volatile u32*)(0xE000E014))      /*SysTick reload value register*/
#define STK_VAL                 *((volatile u32*)(0xE000E018))      /*SysTick current value register*/
#define STK_CALIB               *((volatile u32*)(0xE000E01C))      /*SysTick calibration value register*/











#endif