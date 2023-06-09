
#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_


void RTO_StartOs(void);

void RTO_voidCreateTask(u8 Copy_u8TaskID,u32 Copy_U32Periodicity ,u32 Copy_u32FirstDelay,void(*Pf)(void));



#endif /* RTO_INTERFACE_H_ */
