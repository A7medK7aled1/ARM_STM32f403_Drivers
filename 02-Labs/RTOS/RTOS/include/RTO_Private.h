/*
 * RTO_Private.h
 *
 *  Created on: May 24, 2023
 *      Author: Alsabagh
 */

#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct
{
	void (*Pf)(void) ;
	u32 First_Delay  ;
	u32 Periodicity  ;

}TCB_t;

TCB_t  Task_Arr[No_Of_Tasks] = {NULL} ;

static void RTO_Scheduler(void);



#endif /* RTO_PRIVATE_H_ */
