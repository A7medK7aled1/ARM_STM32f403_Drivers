/****************************************************************/
/****************************************************************/
/*****************		Author:Ahmed Khaled		*****************/
/*****************		Lyer:HAL				*****************/
/*****************		SWC:SSD					*****************/
/*****************		Version:1.00			*****************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"




void SSD_voidTurnOn(SSD_T *SSD)
{
	static u8 Local_u8SSDNumberArr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE };

	if(SSD->Conn_Type==COM_ANODE)
	{
		GPIO_u8SetPinValue(SSD->SSD_Enable_Port,SSD->SSD_Enable_Pin,HIGH);
		GPIO_u8SetPortValue(SSD->SSD_Port,Local_u8SSDNumberArr[SSD->SSD_Number]);

	}
	else if(SSD->Conn_Type==COM_CATHOD)
	{
		GPIO_u8SetPinValue(SSD->SSD_Enable_Port,SSD->SSD_Enable_Pin,LOW);
		GPIO_u8SetPortValue(SSD->SSD_Port,~Local_u8SSDNumberArr[SSD->SSD_Number]);
	}

}

void SSD_voidTurnOff(SSD_T *SSD)
{
	if(SSD->Conn_Type==COM_ANODE)
	{
		GPIO_u8SetPinValue(SSD->SSD_Enable_Port,SSD->SSD_Enable_Pin,LOW);


	}
	else if(SSD->Conn_Type==COM_CATHOD)
	{
		GPIO_u8SetPinValue(SSD->SSD_Enable_Port,SSD->SSD_Enable_Pin,HIGH);

	}
}



