#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"SYSTICK_Register.h"
#include"SYSTICK_Interface.h"
#include"SYSTICK_Private.h"
#include"SYSTICK_Config.h"


void STK_voidInit(void)
{
    /*Select Clock Source for SYSTICK*/
    #if CLK_PRE == PRESCALER_8

    CLR_BIT(STK_CTRL,CLK_SOURCE);

    #elif CLK_PRE == PRESCALER_1

    SET_BIT(STK_CTRL,CLK_SOURCE);

    #else
    #error "Wrong CLK_SOURC Configuration"
    #endif

    /*Select SYSTICK Interrupt Status*/
    #if SYSTICK_INT == DISABLE

    CLR_BIT(STK_CTRL,TICK_INT);

    #elif SYSTICK_INT == ENABLE

    SET_BIT(STK_CTRL,TICK_INT);

    #else
    #error "Wrong Interrupt Configuration"
    #endif

    /*Enable SYSTICK */
    SET_BIT(STK_CTRL,SYSTICK_ENABLE);

}
void STK_voidSetBusyWait(u32 Copy_u32Time)
{
    if(Copy_u32Time<=SYSTICK_MAX)
    {
        STK_VAL=Copy_u32Time;
    }
    else
    {
        /*Do Nothing*/
    }

        /*Enable SYSTICK */
    SET_BIT(STK_CTRL,SYSTICK_ENABLE);

    /*Polling until Counter Reaches to Zero this flag will Set*/
    while(!GET_BIT(STK_CTRL,COUNT_FLAG));


        /*Disable SYSTICK */
    CLR_BIT(STK_CTRL,SYSTICK_ENABLE);

}

u32 STK_u32GetElapsedTime(void)
{
    u32 Local_u32ElapsedTime=0;

    Local_u32ElapsedTime=STK_VAL-STK_LOAD;

    return Local_u32ElapsedTime;

}
u32 STK_u32GetRemainingTime(void)
{
    return STK_LOAD;

}

