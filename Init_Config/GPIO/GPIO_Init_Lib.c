#include "GPIO_INIT_LIB.H"

void GPIO_Init_Lib()
{
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPAEN,ENABLE);	//使能GPIO端口时钟
	
	Typedef
	
	GPIO_Init(GPIOA,&);
}
