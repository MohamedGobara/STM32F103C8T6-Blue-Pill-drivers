#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void  SysTick_vInit(void);

void  SysTick_vDelayus(const uint32_t local_time);


void  SysTick_vDelayms( uint32_t local_time);


void SysTick_vFunUS(const uint32_t local_time, void (*local_ptrFun)(void))  ;

#endif /* SYSTICK_INTERFACE_H */
