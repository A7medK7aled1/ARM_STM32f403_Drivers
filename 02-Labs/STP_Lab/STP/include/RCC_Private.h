/*********************************************************/
/***        Author : Ahmed Khaled 					   ***/
/***        SWC : Reset & Clock Control (RCC)		   ***/
/***        Version : V1				               ***/
/*********************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define HSE_CRYSTAL                 0
#define HSE_RC		                1
#define	HSI			                2
#define	PLL			                3

#define AHP_PRE_MASK                0xffffff0f          

#define AHP_PRE_DIV_0               0
#define AHP_PRE_DIV_2               8
#define AHP_PRE_DIV_4               9
#define AHP_PRE_DIV_8               10
#define AHP_PRE_DIV_16              11
#define AHP_PRE_DIV_64              12
#define AHP_PRE_DIV_128             13
#define AHP_PRE_DIV_256             14
#define AHP_PRE_DIV_512             15


#define ABP1_PRE_MASK                0xFFFFE3FF

#define ABP1_PRE_DIV_0               0
#define ABP1_PRE_DIV_2               4
#define ABP1_PRE_DIV_4               5
#define ABP1_PRE_DIV_8               6
#define ABP1_PRE_DIV_16              7


#define DISABLE						 0
#define ENABLE						 1


#define ABP2_PRE_MASK                0xFFFF1FFF

#define ABP2_PRE_DIV_0               0
#define ABP2_PRE_DIV_2               4
#define ABP2_PRE_DIV_4               5
#define ABP2_PRE_DIV_8               6
#define ABP2_PRE_DIV_16              7

#endif /* RCC_PRIVATE_H_ */
