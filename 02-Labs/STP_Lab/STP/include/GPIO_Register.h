/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Genral Purpose Input Output (GPIO)   ***/
/***        Version : V1				               ***/
/*********************************************************/
#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_


#define  GPIOA_BASE_ADRESS      0x40020000                                          /*Base Address for GPIOA*/
#define  GPIOB_BASE_ADRESS      0x40020400                                          /*Base Address for GPIOB*/
#define  GPIOC_BASE_ADRESS      0x40020800                                          /*Base Address for GPIOC*/


#define GPIOA_MODER				*((volatile u32*)(GPIOA_BASE_ADRESS+0x00))            /*GPIO PortA Mode Register*/
#define GPIOB_MODER				*((volatile u32*)(GPIOB_BASE_ADRESS+0x00))            /*GPIO PortB Mode Register*/
#define GPIOC_MODER				*((volatile u32*)(GPIOC_BASE_ADRESS+0x00))            /*GPIO PortC Mode Register*/




#define GPIOA_OTYPER             *((volatile u32*)(GPIOA_BASE_ADRESS+0x04))           /*GPIO PortA Output Type Register*/           
#define GPIOB_OTYPER             *((volatile u32*)(GPIOB_BASE_ADRESS+0x04))           /*GPIO PortB Output Type Register*/
#define GPIOC_OTYPER             *((volatile u32*)(GPIOC_BASE_ADRESS+0x04))           /*GPIO PortC Output Type Register*/


#define GPIOA_OSPEEDR            *((volatile u32*)(GPIOA_BASE_ADRESS+0x08))           /*GPIO PortA Output Speed Register*/
#define GPIOB_OSPEEDR            *((volatile u32*)(GPIOB_BASE_ADRESS+0x08))           /*GPIO PortB Output Speed Register*/
#define GPIOC_OSPEEDR            *((volatile u32*)(GPIOC_BASE_ADRESS+0x08))           /*GPIO PortC Output Speed Register*/

#define GPIOA_ODR			   	*((volatile u32*)(GPIOA_BASE_ADRESS+0x14))            /*GPIO PortA Output Data Register*/
#define GPIOB_ODR			   	*((volatile u32*)(GPIOB_BASE_ADRESS+0x14))            /*GPIO PortB Output Data Register*/
#define GPIOC_ODR			   	*((volatile u32*)(GPIOC_BASE_ADRESS+0x14))            /*GPIO PortC Output Data Register*/



#define GPIOA_PUPDR			   	*((volatile u32*)(GPIOA_BASE_ADRESS+0x0c))            /*GPIO port A pull-up/pull-down register*/
#define GPIOB_PUPDR			   	*((volatile u32*)(GPIOB_BASE_ADRESS+0x0c))            /*GPIO port B pull-up/pull-down register*/
#define GPIOC_PUPDR			   	*((volatile u32*)(GPIOC_BASE_ADRESS+0x0c))            /*GPIO port C pull-up/pull-down register*/




#define GPIOA_IDR			   	*((volatile u32*)(GPIOA_BASE_ADRESS+0x10))            /*GPIO PortA input data register */
#define GPIOB_IDR			   	*((volatile u32*)(GPIOB_BASE_ADRESS+0x10))            /*GPIO PortB input data register */
#define GPIOC_IDR			   	*((volatile u32*)(GPIOC_BASE_ADRESS+0x10))            /*GPIO PortC input data register */

#endif
