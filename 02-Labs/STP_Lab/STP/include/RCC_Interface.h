/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Reset & Clock Control (RCC)		   ***/
/***        Version : V1				               ***/
/*********************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/**********************************************************************************/
/*******Description : This function Select the CLK Source of the System************/
/*******              and Select the Prescaler for the AHP1 ,APB1 and APB2  *******/
/*******Input : Use Configuration file to Select your Configuration ***************/
/*******Output: No Retuen (void)***************************************************/
/**********************************************************************************/

void RCC_voidInitSysCLK(void);

/**********************************************************************************/
/*******Description : This function Enable the Peripheral CLK Based on ************/
/*******              the peripheral Connected with AHP1 ,APB1 and APB2  **********/
/*******Input : Copy_u8BusID : AHP1 ,APB1 and APB2 ********************************/
/*******Input : Copy_u8PeripheralID : GPIO_A,GPIO_B,GPIO_C etc ********************/
/*******Output: No Retuen (void)***************************************************/
/**********************************************************************************/

void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/**********************************************************************************/
/*******Description : This function Disable the Peripheral CLK Based on ***********/
/*******              the peripheral Connected with AHP1 ,APB1 and APB2  **********/
/*******Input : Copy_u8BusID : AHP1 ,APB1 and APB2 ********************************/
/*******Input : Copy_u8PeripheralID : GPIO_A,GPIO_B,GPIO_C etc ********************/
/*******Output: No Retuen (void)***************************************************/
/**********************************************************************************/

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);


/*Buses ID*/
#define AHP1    0
#define AHP2    1
#define APB1    2
#define APB2    3


/*Peripheral ID*/

/*AHP1 Bus Peripherals*/
#define AHP1_GPIOA              0
#define AHP1_GPIOB              1
#define AHP1_GPIOC              2
#define AHP1_DMA1               21
#define AHP1_DMA2               22

/*AHP2 Bus Peripherals*/
#define AHP2_USB                7

/*APB1 Bus Peripherals*/
#define APB1_TIM2               0
#define APB1_TIM3               1
#define APB1_TIM4               2
#define APB1_TIM5               3
#define APB1_WWDG               11
#define APB1_SPI2               14
#define APB1_SPI3               15
#define APB1_USART2             17
#define APB1_I2C1               21
#define APB1_I2C2               22
#define APB1_I2C3               23
#define APB1_PWR                28

/*APB2 Bus Peripherals*/
#define APB2_TIM1               0
#define APB2_USART1             4
#define APB2_USART6             5
#define APB2_ADC1               8
#define APB2_SDIO               11
#define APB2_SPI1               12
#define APB2_SPI4               13
#define APB2_SYSCFG             14
#define APB2_TIM9               16
#define APB2_TIM10              17
#define APB2_TIM11              18






















#endif /* RCC_INTERFACE_H_ */
