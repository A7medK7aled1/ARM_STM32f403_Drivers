/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Genral Purpose Input Output (GPIO)   ***/
/***        Version : V1				               ***/
/*********************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Register.h"




u8 GPIO_u8SetPinMode(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinMode)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Port == GPIO_A)
	{
		switch (Copy_u8PinMode)
		{
		case INPUT:		CLR_BIT(GPIOA_MODER,(2*Copy_u8PinNumber));
				   	   	CLR_BIT(GPIOA_MODER,(2*Copy_u8PinNumber+1));break;

		case OUTPUT:	SET_BIT(GPIOA_MODER,(2*Copy_u8PinNumber));
						CLR_BIT(GPIOA_MODER,(2*Copy_u8PinNumber+1));break;


		case AF:		CLR_BIT(GPIOA_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOA_MODER,(2*Copy_u8PinNumber+1));break;


		case ANALOG:	SET_BIT(GPIOA_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOA_MODER,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_B)
	{
		switch (Copy_u8PinMode)
		{
		case INPUT:		CLR_BIT(GPIOB_MODER,(2*Copy_u8PinNumber));
				   	   	CLR_BIT(GPIOB_MODER,(2*Copy_u8PinNumber+1));break;

		case OUTPUT:	SET_BIT(GPIOB_MODER,(2*Copy_u8PinNumber));
						CLR_BIT(GPIOB_MODER,(2*Copy_u8PinNumber+1));break;


		case AF:		CLR_BIT(GPIOB_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOB_MODER,(2*Copy_u8PinNumber+1));break;


		case ANALOG:	SET_BIT(GPIOB_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOB_MODER,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_C)
	{
		switch (Copy_u8PinMode)
		{
		case INPUT:		CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
				   	   	CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;

		case OUTPUT:	SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
						CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;


		case AF:		CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;


		case ANALOG:	SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
						SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	return Local_u8ErrorState;
}

u8 GPIO_u8SetPinType(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinType)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8PinType == PUSH_PULL)
	{
		switch (Copy_u8Port)
		{
			case GPIO_A:CLR_BIT(GPIOA_OTYPER,Copy_u8PinNumber);break;
			case GPIO_B:CLR_BIT(GPIOB_OTYPER,Copy_u8PinNumber);break;
			case GPIO_C:CLR_BIT(GPIOC_OTYPER,Copy_u8PinNumber);break;
			default:Local_u8ErrorState=NOK;break;

		}

	}
	else if(Copy_u8PinType == OPEN_DRAIN)
	{
		switch (Copy_u8Port)
		{
			case GPIO_A:SET_BIT(GPIOA_OTYPER,Copy_u8PinNumber);break;
			case GPIO_B:SET_BIT(GPIOB_OTYPER,Copy_u8PinNumber);break;
			case GPIO_C:SET_BIT(GPIOC_OTYPER,Copy_u8PinNumber);break;
			default:Local_u8ErrorState=NOK;break;

		}

	}
	return Local_u8ErrorState;

}

u8 GPIO_u8SetPinSpeed(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinSpeed)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8Port == GPIO_A)
	{
		switch (Copy_u8PinSpeed)
		{
		case LOW_SPEED:			CLR_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber));
				   	   			CLR_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber+1));break;

		case MEDUIM_SPEED:		SET_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber));
								CLR_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber+1));break;


		case HIGH_SPEED:		CLR_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber));
								SET_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber+1));break;


		case VHIGH_SPEED:		SET_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber));
								SET_BIT(GPIOA_OSPEEDR,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_B)
	{
		switch (Copy_u8PinSpeed)
		{
		case LOW_SPEED:			CLR_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber));
				   	   			CLR_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber+1));break;

		case MEDUIM_SPEED:		SET_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber));
								CLR_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber+1));break;


		case HIGH_SPEED:		CLR_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber));
								SET_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber+1));break;


		case VHIGH_SPEED:		SET_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber));
								SET_BIT(GPIOB_OSPEEDR,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_C)
	{
		switch (Copy_u8PinSpeed)
		{
		case LOW_SPEED:			CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
				   	   			CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;

		case MEDUIM_SPEED:		SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
								CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;


		case HIGH_SPEED:		CLR_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
								SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;


		case VHIGH_SPEED:		SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber));
								SET_BIT(GPIOC_MODER,(2*Copy_u8PinNumber+1));break;

		default:Local_u8ErrorState=NOK;break;
		}

	}
	return Local_u8ErrorState;

}

u8 GPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState=OK;

	if(Copy_u8Port == GPIO_A)
	{
		switch(Copy_u8PinValue)
		{
			case LOW:CLR_BIT(GPIOA_ODR,Copy_u8PinNumber);break;
			case HIGH:SET_BIT(GPIOA_ODR,Copy_u8PinNumber);break;
			default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_B)
	{
		switch(Copy_u8PinValue)
		{
			case LOW:CLR_BIT(GPIOB_ODR,Copy_u8PinNumber);break;
			case HIGH:SET_BIT(GPIOB_ODR,Copy_u8PinNumber);break;
			default:Local_u8ErrorState=NOK;break;
		}

	}
	else if(Copy_u8Port == GPIO_C)
	{
		switch(Copy_u8PinValue)
		{
			case LOW:CLR_BIT(GPIOC_ODR,Copy_u8PinNumber);break;
			case HIGH:SET_BIT(GPIOC_ODR,Copy_u8PinNumber);break;
			default:Local_u8ErrorState=NOK;break;
		}

	}

	return Local_u8ErrorState;
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNumber)
{
	u8 Local_u8PinReading=OK;
	switch(Copy_u8Port)
	{
		case GPIO_A:Local_u8PinReading=GET_BIT(GPIO_A,Copy_u8PinNumber);break;
		case GPIO_B:Local_u8PinReading=GET_BIT(GPIO_B,Copy_u8PinNumber);break;
		case GPIO_C:Local_u8PinReading=GET_BIT(GPIO_C,Copy_u8PinNumber);break;														
	}

	return Local_u8PinReading;


}

u8 GPIO_u8SetPortValue(u8 Copy_u8Port,u16 Copy_u16PortValue)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Port)
	{
		case GPIO_A:GPIOA_ODR=Copy_u16PortValue;break;
		case GPIO_B:GPIOB_ODR=Copy_u16PortValue;break;
		case GPIO_C:GPIOC_ODR=Copy_u16PortValue;break;
		default:Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState;


}


