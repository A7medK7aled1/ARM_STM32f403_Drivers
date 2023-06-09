#include "STD_Types.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "STP_Interface.h"

int main(void) {

	RCC_voidInitSysCLK();
	RCC_voidEnablePeripheralClk(AHP1,AHP1_GPIOA);

	GPIO_u8SetPinMode(GPIO_A,PIN0,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN1,OUTPUT);
	GPIO_u8SetPinMode(GPIO_A,PIN2,OUTPUT);

	SYSTICK_voidInit();

	STP_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 8; i++)
		{
			STP_voidSendSynchronous(1 << i);
			SYSTICK_voidSetBusyWait(2000000);
		}
	}

	return 0;
}
