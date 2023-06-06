

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_Interface.h"
#include "SYSTICK_Interface.h"

#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"

void TFT_voidInitialize   (void)
{
	
	GPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	STK_voidDelayMs(100);
	GPIO_voidWriteData(TFT_RST_PIN,_LOW);
	STK_voidDelayMs(1);
	GPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	STK_voidDelayMs(100);
	GPIO_voidWriteData(TFT_RST_PIN,_LOW);
	STK_voidDelayMs(100);
	GPIO_voidWriteData(TFT_RST_PIN,_HIGH);
	STK_voidDelayMs(120000);

	voidWriteCommand(0x11);

	STK_voidDelayMs(150000);
	voidWriteCommand(0x3A);
	voidWriteData   (0x05);

	voidWriteCommand(0x29);
}


void TFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		voidWriteData(Data);
		Data = Copy_Image[counter] & 0x00ff;
		voidWriteData(Data);
	}


}

static void voidWriteCommand(u8 Copy_u8Command)
{

	GPIO_voidWriteData(TFT_A0_PIN,_LOW);

	SPI1_voidSendDataU8(Copy_u8Command) ;
}

static void voidWriteData   (u8 Copy_u8Data)
{

	GPIO_voidWriteData(TFT_A0_PIN,_HIGH);

	SPI1_voidSendDataU8(Copy_u8Data) ;
}



