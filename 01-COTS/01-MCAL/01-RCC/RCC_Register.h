/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Reset & Clock Control (RCC)		   ***/
/***        Version : V1				               ***/
/*********************************************************/





#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


#define RCC_BASE_ADDRESS                    0x40023800

#define RCC_CR                              *((volatile u32*)(RCC_BASE_ADDRESS+0x00))       /*RCC Control Register to Select the System CLK Source*/

#define RCC_CR_HSION                         0                                              /*Enable HSI CLK*/                        
#define RCC_CR_HSIRDY                        1                                              /*Check HSI CLK Status*/
#define RCC_CR_HSEON                         16                                             /*Enable HSE CLK*/   
#define RCC_CR_HSERDY                        17                                             /*Check HSE CLK Status*/
#define RCC_CR_HSEBYP                        18                                             /*HSE Bypass CLK Source using RC CLK*/
#define RCC_CR_CSS                           19                                             /*CLK Security System*/
#define RCC_CR_PLLON                         24                                             /*Enable PLL CLK*/
#define RCC_CR_PLLRDY                        25                                             /*Check PLL CLK Status*/




#define RCC_PLLCFGR                         *((volatile u32*)(RCC_BASE_ADDRESS+0x04))       /*PLL Configuration Register*/

#define RCC_CFGR                            *((volatile u32*)(RCC_BASE_ADDRESS+0x08))       /*RCC clock configuration register*/

#define RCC_CFGR_SW0                        0                                               /*Bit 0 to Select CLK Source*/
#define RCC_CFGR_SW1                        1                                               /*Bit 1 to Select CLK Source*/


#define RCC_AHB1ENR                         *((volatile u32*)(RCC_BASE_ADDRESS+0x30))       /*AHB1 peripheral clock enable register*/
#define RCC_AHB2ENR                         *((volatile u32*)(RCC_BASE_ADDRESS+0x34))       /*AHB2 peripheral clock enable register*/
#define RCC_APB1ENR                         *((volatile u32*)(RCC_BASE_ADDRESS+0x40))       /*APB1 peripheral clock enable register*/
#define RCC_APB2ENR                         *((volatile u32*)(RCC_BASE_ADDRESS+0x44))       /*APB2 peripheral clock enable register*/





#endif /* RCC_REGISTER_H_ */
