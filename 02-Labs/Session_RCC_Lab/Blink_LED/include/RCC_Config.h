/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Reset & Clock Control (RCC)		   ***/
/***        Version : V1				               ***/
/*********************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*RCC_SYSCLKSRC Options
              1-HSE_CRYSTAL 
              2-HSE_RC		
              3-HSI			
              4-PLL			
                    */

#define RCC_SYSCLKSRC       HSE_CRYSTAL
/*CLK_SECU Options
 * 			1-ENABLE
 * 			2-DISABLE*/

#define CLK_SECU		DISABLE

/*AHP_PRE Options
               1-AHP_PRE_DIV_0 
               2-AHP_PRE_DIV_2 
               3-AHP_PRE_DIV_4 
               4-AHP_PRE_DIV_8 
               5-AHP_PRE_DIV_16
               6-AHP_PRE_DIV_64
               7-AHP_PRE_DIV_12
               8-AHP_PRE_DIV_25
               9-AHP_PRE_DIV_51
               */
#define AHP_PRE             AHP_PRE_DIV_2


/*ABP1_PRE Options
               1-ABP1_PRE_DIV_0 
               2-ABP1_PRE_DIV_2 
               3-ABP1_PRE_DIV_4 
               4-ABP1_PRE_DIV_8 
               5-ABP1_PRE_DIV_16

               *

*/
#define ABP1_PRE        ABP1_PRE_DIV_8



/*ABP2_PRE Options
               1-ABP2_PRE_DIV_0 
               2-ABP2_PRE_DIV_2 
               3-ABP2_PRE_DIV_4 
               4-ABP2_PRE_DIV_8 
               5-ABP2_PRE_DIV_16

               *

*/
#define ABP2_PRE        ABP2_PRE_DIV_8

#endif /* RCC_CONFIG_H_ */
