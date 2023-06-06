

#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H


 
#define Base_Adress_EXTI			      0x40013C00
 
 
#define  SYSCFG_EXTICR1                  (*(volatile u32*)(0x40013808))

 
#define   EXTI_CONFG_MASK1                0xFFFFFFF0UL
#define   EXTI_CONFG_MASK2                0xFFFFFF0FUL
#define   EXTI_CONFG_MASK3                0xFFFFF0FFUL
#define   EXTI_CONFG_MASK4                0xFFFF0FFFUL



typedef struct
{

	volatile  u32   IMR		;				
	volatile  u32   EMR		;				
	volatile  u32   RTSR	;				
	volatile  u32   FTSR	;				
	volatile  u32   SWIER   ;				
	volatile  u32   PR		;				
}EXTI_t;									




#define EXTI_Ptr 					 (( volatile  EXTI_t * ) Base_Adress_EXTI )			



#define LINE_0			0
#define LINE_1			1
#define LINE_2			2
#define LINE_3			3
#define LINE_4			4
#define LINE_5			5
#define LINE_6			6
#define LINE_7			7
#define LINE_8			8
#define LINE_9			9
#define LINE_10			10
#define LINE_11			11
#define LINE_12			12
#define LINE_13			13
#define LINE_14			14
#define LINE_15			15



#define Rising_Edage				0
#define Falling_Edage			    1
#define On_Change					2									

#endif 
