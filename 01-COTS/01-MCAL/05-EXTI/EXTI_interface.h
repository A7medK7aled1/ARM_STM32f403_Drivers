

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI0     0
#define EXTI1     1

#define   RISING_EDGE     0

#define   FALLING_EDGE   1


#define    ON_CHANGE       2


void MEXTI_voidInit(void)  ;


void MEXTI_voidSetSignalLatch(u8 Copy_Exti_Line ,u8 Copy_EXTI_Sense_Mode )  ;


void MEXTI_voidEnableEXTI(u8 Copy_u8Line) ;


void MEXTI_voidDisableEXTI(u8 Copy_u8Line);


void MEXIT_voidSoftwareInterrput(u8 Copy_u8Line);


void MEXTI0_voidSetCallBack( void (*ptr) (void));
void MEXTI1_voidSetCallBack( void (*ptr) (void));



void MEXTI_voidSetEXTIConfiguration(u8 Copy_u8ExtiLine , u8 Copy_u8GpioPortNum );
#endif  
