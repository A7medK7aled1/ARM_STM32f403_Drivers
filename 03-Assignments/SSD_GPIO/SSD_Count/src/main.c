#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SSD_interface.h"



void APP_voidDelayMs(u32 Copy_u32Delay);



void main(void)
{
	u8 i=0;
	SSD_T SSD1;


	RCC_voidInitSysCLK();

	RCC_voidEnablePeripheralClk(AHP1 , AHP1_GPIOA);
	GPIO_u8SetPinMode(GPIO_A,PIN0,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN1,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN2,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN3,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN4,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN5,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN6,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN13,INPUT);
	GPIO_u8SetPinMode(GPIO_B,PIN0,OUTPUT);






	while(1)
	{
		i=GPIO_u8GetPinValue(GPIO_A,PIN13);


		SSD_T SSD1={GPIO_A,COM_CATHOD,i,GPIO_B,PIN8};

		SSD_voidTurnOn(&SSD1);








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
