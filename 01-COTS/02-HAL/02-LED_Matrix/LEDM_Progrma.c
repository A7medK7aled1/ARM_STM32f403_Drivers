#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

#include "LEDM_Config.h"
#include "LEDM_Interface.h"
#include "LEDM_Private.h"





void LEDMAT_voidInit(void)
{
    u8 row, col;
    u8 rows[] = {ROW0, ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7};
    u8 cols[] = {COLUM0, COLUM1, COLUM2, COLUM3, COLUM4, COLUM5, COLUM6, COLUM7};
    
    /* Set Mode For Rows and Cols as Output */
    for (row = 0; row < 8; row++)
    {
        GPIO_u8SetPinMode(ROW_PORT,rows[row],OUTPUT);
        GPIO_u8SetPinSpeed(ROW_PORT,rows[row],MEDUIM_SPEED);
        GPIO_u8SetPinType(ROW_PORT,rows[row],PUSH_PULL);

    }
    
    for (col = 0; col < 8; col++)
    {

        GPIO_u8SetPinMode(COLUM_PORT,cols[col],OUTPUT);
        GPIO_u8SetPinSpeed(COLUM_PORT,cols[col],MEDUIM_SPEED);
        GPIO_u8SetPinType(COLUM_PORT,cols[col],PUSH_PULL);

    }
}


static void LEDMAT_voidDisableCols(void)
{
    u8 col;
    u8 cols[] = {COLUM0, COLUM1, COLUM2, COLUM3, COLUM4, COLUM5, COLUM6, COLUM7};
    
    for (col = 0; col < 8; col++)
    {
        GPIO_voidSetPinValue(COLUM_PORT,cols[col], HIGH);
    }
}






static void LEDMAT_voidSetRowVlaues(u8 Copy_u8Frame)
{
    u8 row;
    u8 rows[] = {ROW0, ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7};    
    for (row = 0; row < 8; row++)
    {
        GPIO_voidSetPinValue(ROW_PORT,rows[row], GET_BIT(Copy_u8Frame, row));
    }
}



void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{
    u8 col;
    u8 cols[] = {COLUM0, COLUM1, COLUM2, COLUM3, COLUM4, COLUM5, COLUM6, COLUM7};

    for (col = 0; col < 8; col++)
    {
        /* Disable All Columns */
        LEDMAT_voidDisableCols();
        
        /* Set Row Value */
        LEDMAT_voidSetRowVlaues(Copy_u8Frame[col]);
        
        /* Enable Current Column */
        MGPIO_voidSetPinValue(COLUM_PORT,cols[col], LOW);
        
        // Delay 1042 us
        STK_voidSetBusyWait(2500); // 2.5ms
    }
}

