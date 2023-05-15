/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Genral Purpose Input Output (GPIO)   ***/
/***        Version : V1				               ***/
/*********************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_



#define  GPIO_A			0
#define  GPIO_B			1
#define  GPIO_C			2




#define INPUT			0
#define OUTPUT			1
#define AF				2
#define ANALOG			3




#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7
#define PIN8            8
#define PIN9            9
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15
#define PIN16           16

#define PUSH_PULL       0
#define OPEN_DRAIN      1

#define HIGH			1
#define LOW				0

#define PORT_HIGH       0xff
#define PORT_LOW        0

#define LOW_SPEED       0
#define MEDUIM_SPEED    1
#define HIGH_SPEED      2
#define VHIGH_SPEED     3

#define NO_PULL         0
#define PULL_UP         1
#define PULL_DOWN       2


u8 GPIO_u8SetPinMode(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinMode);

u8 GPIO_u8SetPinType(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinType);

u8 GPIO_u8SetPinSpeed(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinSpeed);

u8 GPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinValue);

u8 GPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber);

#endif
