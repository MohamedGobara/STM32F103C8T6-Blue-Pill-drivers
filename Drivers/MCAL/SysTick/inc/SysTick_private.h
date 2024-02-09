#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H




#define SysTick_BASE_ADDRESS 0xE000E010U



typedef struct {
	uint32_t CTRL ;
	uint32_t LOAD ;
	uint32_t VAL ;
	uint32_t CALIB ;

}SysTick_REG ;



#define SysTick  ((SysTick_REG*)SysTick_BASE_ADDRESS)




#endif /* SYSTICK_PRIVATE_H */
