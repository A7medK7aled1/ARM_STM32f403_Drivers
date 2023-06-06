#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_Interface.h"


#define NVIC_EXTI0     6


volatile u8 Global_u8Flag = 0 ;

volatile u32 Global_u32FrameData[50] = {0} ; 

volatile u8 Global_u8EdgeCounter   = 0 ;


volatile u8 Global_u8Data =  0 ;

void App_voidPlay(void)
{

	switch(Global_u8Data)
	{
	case 70: MGPIO_voidWriteData(_GPIOA_PORT, _PIN_2, _HIGH);
	break ;
	case 71:MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, _HIGH);break;
	case 72:MGPIO_voidWriteData(_GPIOA_PORT, _PIN_3, _HIGH);break;
	case 69 : MGPIO_voidWriteData(_GPIOA_PORT, _PIN_1, _LOW);
				MGPIO_voidWriteData(_GPIOA_PORT, _PIN_2, _LOW);
				MGPIO_voidWriteData(_GPIOA_PORT, _PIN_3, _LOW);
	break ;
	}
}

void App_voidTakeAction(void)
{
	u8 i ;

	Global_u8Data = 0 ;
	if((Global_u32FrameData[0]>= 10000) && (Global_u32FrameData[0] <= 14000))
	{
		for(i = 0 ; i<8 ;i++)
		{
			if ((Global_u32FrameData[17+i]>= 2000) && (Global_u32FrameData[17+i] <= 2300))
			{
				
				SET_BIT(Global_u8Data,i);
			}
			else
			{
				
				CLR_BIT(Global_u8Data,i);
			}
		}
		App_voidPlay();
	}
	else
	{

	}
	Global_u8Flag = 0 ;
	Global_u32FrameData[0] = 0 ;
	Global_u8EdgeCounter   = 0 ;
}

void App_voidGetFrame(){


	if(Global_u8Flag == 0)
	{
		MSTK_voidSetIntervalSingle(1000000,App_voidTakeAction);
		Global_u8Flag = 1 ;
	}
	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime() ;
		MSTK_voidSetIntervalSingle(1000000,App_voidTakeAction);
		Global_u8EdgeCounter++;
	}

}



int main(void)
{
	
	RCC_voidInitSystemClk();

	
	RCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;
	RCC_voidEnablePeripheralClock(APB2, PERIPHERAL_EN_SYSCFG) ;

	for(u8 PIN = 1 ;PIN <=3 ;PIN++ )
	{
		
		GPIO_voidSetPinMode(_GPIOA_PORT, PIN, _MODE_OUTPUT) ;
		
		GPIO_voidSetPinOutPutType(_GPIOA_PORT,PIN,_OUTPUT_TYPE_PUSH_PULL);
		
		GPIO_voidSetPinOutSpeed(_GPIOA_PORT, PIN, _OUTPUT_SPEED_LOW);
	}


	
	GPIO_voidSetPinMode(_GPIOA_PORT, _PIN_0, _MODE_INPUT) ;     


	
	GPIO_voidSetPullType(_GPIOA_PORT, _PIN_0, _PULL_OFF);




	EXTI0_voidSetCallBack(App_voidGetFrame);


	EXTI_voidSetEXTIConfiguration(EXTI0, _GPIOA_PORT);

	EXTI_voidSetSignalLatch(EXTI0, FALLING_EDGE);

	
	NVIC_voidEnableInterrupt(NVIC_EXTI0);

	
	STK_voidInit(); 
	while(1)
	{
	}
}
















