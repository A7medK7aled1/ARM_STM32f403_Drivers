/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Reset & Clock Control (RCC)		   ***/
/***        Version : V1				               ***/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
#include "RCC_Register.h"

void RCC_voidInitSysCLK(void)
{
	u32 Loca_u32Temporary = AHP_PRE ;


#if   RCC_SYSCLKSRC == HSE_CRYSTAL			/*Not Bypass Using External Crystal or Ceramic CLK*/


	/** system clk source = HSE **/
	SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

	/** disable Bypass **/
	CLR_BIT(RCC_CR,RCC_CR_HSEBYP);

	/** Enable HSE **/
	SET_BIT(RCC_CR,RCC_CR_HSEON);

	while(GET_BIT(RCC_CR,RCC_CR_HSERDY)==0);	/*Wait until the HSE Crystal CLK being Stable*/



#elif RCC_SYSCLKSRC == HSE_RC

	/** system clk source = HSE **/
	SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

	/** Enable Bypass **/
	SET_BIT(RCC_CR,RCC_CR_HSEBYP);

	/** Enable HSE **/
	SET_BIT(RCC_CR,RCC_CR_HSEON);

	while(GET_BIT(RCC_CR,RCC_CR_HSERDY)==0);	/*Wait until the HSE RC CLK being Stable*/


#elif RCC_SYSCLKSRC == HSI


	/** system clk source = HSI **/
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

	/** Enable HSI **/
	SET_BIT(RCC_CR,RCC_CR_HSION);

	while(GET_BIT(RCC_CR,RCC_CR_HSIRDY)==0);	/*Wait until the HSE Crystal CLK being Stable*/




#elif RCC_SYSCLKSRC == PLL
	/****/
#else
#error "Invalid Option selected for CLK"
#endif

#if CLK_SECU  == ENABLE

	SET_BIT(RCC_CR,RCC_CR_CSS);

#elif CLK_SECU  == DISABLE

	CLR_BIT(RCC_CR,RCC_CR_CSS);

#endif

/*Choose Prescaler for AHP*/
RCC_CFGR &=AHP_PRE_MASK;
RCC_CFGR |=(Loca_u32Temporary<<4);



/*Choose Prescaler for APB1*/
Loca_u32Temporary = ABP1_PRE;
RCC_CFGR &=ABP1_PRE_MASK ;
RCC_CFGR |=(Loca_u32Temporary<<10);

/*Choose Prescaler for APB2*/
Loca_u32Temporary = ABP2_PRE;
RCC_CFGR &=ABP2_PRE_MASK ;
RCC_CFGR |=(Loca_u32Temporary<<13);


}



void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	//validation
	if(Copy_u8PeripheralID > 32)
	{
		/*Do nothing*/
	}
	else
	{
		switch(Copy_u8BusID)
		{
		case AHP1:  SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);     break;
		case AHP2:  SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);     break;
		case APB1:  SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);     break;
		case APB2:  SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);     break;
		default:                                                  break;
		}
	}


}

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	if(Copy_u8PeripheralID > 32)
	{
		/*Do nothing*/
	}
	else
	{
		switch(Copy_u8BusID)
		{
		case AHP1:  CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);     break;
		case AHP2:  CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);     break;
		case APB1:  CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);     break;
		case APB2:  CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);     break;
		default:                                                  break;
		}
	}
}
