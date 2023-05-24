#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "LEDM_Interface.h"



void APP_voidDelayMs(u32 Copy_u32Delay);

u8 GLOB_u8DataArr[8] = {0, 255, 9, 9, 9, 9, 255, 0};

void main(void)
{
	u8 i=0;


	RCC_voidInitSysCLK();
	STK_voidInit();

	RCC_voidEnablePeripheralClk(AHP1 , AHP1_GPIOA);
	RCC_voidEnablePeripheralClk(AHP1 , AHP1_GPIOB);

	LEDMAT_voidInit();








	while(1)
	{



		LEDM_voidDisplay(GLOB_u8DataArr);




	}

}

/******************************************Function Implementation *******************************/
void APP_voidDelayMs(u32 Copy_u32Delay)
{

	for(u32 i = 0 ; i <Copy_u32Delay * 300; i++ )
	{
		asm("NOP") ;
	}
}
