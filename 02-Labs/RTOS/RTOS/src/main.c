
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "RTO_Interface.h"

void APP_LED1(void)
{
	static u8 LOC_u8BitVal = 0 ;
	TOG_BIT(LOC_u8BitVal,0) ;
	MGPIO_voidSetPinValue(MGPIOA_PORT,0,LOC_u8BitVal) ;

}
void APP_LED2(void)
{
	static u8 LOC_u8BitVal = 0 ;
	TOG_BIT(LOC_u8BitVal,0) ;
	MGPIO_voidSetPinValue(MGPIOA_PORT,1,LOC_u8BitVal) ;
}
void APP_LED3(void)
{
	static u8 LOC_u8BitVal = 0 ;
	TOG_BIT(LOC_u8BitVal,0) ;
	MGPIO_voidSetPinValue(MGPIOA_PORT,2,LOC_u8BitVal) ;

}
void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	for(u8 i = 0 ; i<3 ; i++)
	{
		/*Set Pin Direction ->> Output*/
		MGPIO_voidSetPinMode(MGPIOA_PORT,i,MGPIO_MODE_OUTPUT) ;
		/*Set Pin Speed*/
		MGPIO_voidSetOutputSpeed(MGPIOA_PORT,i,MGPIO_OUTPUT_SPEED_MEDUIM) ;
		/*Pull Output Type*/
		MGPIO_voidSetOutputType(MGPIOA_PORT,i,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	}

	/*Step 3 : Creat tasks*/
	RTO_voidCreateTask(0,2000 ,0,APP_LED1);
	RTO_voidCreateTask(1,5000 ,1,APP_LED2);
	RTO_voidCreateTask(2,10000,2,APP_LED3);

	/*Step 4 : Start Scheduling*/
	RTO_StartOs();

	/* Loop forever */
	while(1)
	{

	}

}

