/*
 * RTO_Prog.c
 *
 *  Created on: May 24, 2023
 *      Author: Alsabagh
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "RTO_Config.h"
#include "MSTK_Interface.h"
#include "RTO_Private.h"

#include "RTO_Interface.h"



void RTO_StartOs(void)
{
	MSTK_voidInit();
	MSTK_voidCtrlIntState(MSTK_INT_ENABLE);
	MSTK_voidCallBack(RTO_Scheduler);

	// interrupt occar every 1ms
	MSTK_voidStart(2000);

}

void RTO_voidCreateTask(u8 Copy_u8TaskID,u32 Copy_U32Periodicity ,u32 Copy_u32FirstDelay,void(*Pf)(void))
{
	if(Copy_u8TaskID <No_Of_Tasks)
	{
		Task_Arr[Copy_u8TaskID].Periodicity = Copy_U32Periodicity ;
		Task_Arr[Copy_u8TaskID].First_Delay = Copy_u32FirstDelay  ;
		Task_Arr[Copy_u8TaskID].Pf = Pf ;
	}
}




static void RTO_Scheduler(void)
{
	u8 Local_u8Count =0 ;

	for(Local_u8Count = 0 ;Local_u8Count <No_Of_Tasks ;Local_u8Count++)
	{
		if((Task_Arr[Local_u8Count].First_Delay==0)&&(Task_Arr[Local_u8Count].Pf != NULL))
		{
			Task_Arr[Local_u8Count].Pf();
			Task_Arr[Local_u8Count].First_Delay = Task_Arr[Local_u8Count].Periodicity -1 ;
		}
		else
		{
			Task_Arr[Local_u8Count].First_Delay-- ;
		}
	}
}


