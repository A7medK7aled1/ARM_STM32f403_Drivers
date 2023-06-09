#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"

void STP_voidInit()
{
    /*Configure Pins A0, A1, A2 as O/P pins, Push Pull, Ls*/
    GPIO_voidSetPinMode(STP_SERIAL_DATA, OUTPUT);
    GPIO_voidSetPinMode(STP_STORE_CLOCK, OUTPUT);
    GPIO_voidSetPinMode(STP_SHIFT_CLOCK, OUTPUT);
}

void STP_voidSendSynchronus(u8 Copy_DataToBeSent)
{
    s8 Local_u8Counter;
    u8 Local_u8Bit;
    for(Local_u8Counter = 7; Local_u8Counter >= 0; Local_u8Counter--)
    {
        Local_u8Bit = GET_BIT(Copy_DataToBeSent, Local_u8Counter);

        GPIO_voidSetPinValueDirectAccess(STP_SERIAL_DATA, Local_u8Bit);

        /*Send Pulse to Shift Clock*/
        GPIO_voidSetPinValueDirectAccess(STP_SHIFT_CLOCK, PIN_SET);
        STK_voidSetBusyWait(1);
        GPIO_voidSetPinValueDirectAccess(STP_SHIFT_CLOCK, PIN_RST);
        STK_voidSetBusyWait(1);
    }
    /*Send Pulse to Shift Clock*/
    GPIO_voidSetPinValueDirectAccess(STP_STORE_CLOCK, PIN_SET);
    STK_voidSetBusyWait(1);
    GPIO_voidSetPinValueDirectAccess(STP_STORE_CLOCK, PIN_RST);
    STK_voidSetBusyWait(1);
}
