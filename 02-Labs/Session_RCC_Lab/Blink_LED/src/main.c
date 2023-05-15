#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"


void APP_voidDelayMs(u32 Copy_u32Delay);


#define GPIOA_MODER	   (*((volatile u32*)(0x40020000)))//input or output

#define GPIOA_ODR	   (*((volatile u32*)(0x40020014)))// high or low

void main(void)
{

	RCC_voidInitSysCLK();

	RCC_voidEnablePeripheralClk(AHP1 , AHP1_GPIOA);

	SET_BIT(GPIOA_MODER	,0);

	SET_BIT(GPIOA_ODR , 0);

	while(1)
	{

		/*Step 5 : Toggle LED */
		CLR_BIT(GPIOA_ODR , 0);
		APP_voidDelayMs(10000);
		SET_BIT(GPIOA_ODR , 0);
		APP_voidDelayMs(10000);


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
