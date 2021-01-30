#include "stm32G4xx.h"

void Systick_Init()
{
	SysTick->LOAD = SystemCoreClock/10 - 1;
	SysTick->CTRL = 0x00000007;
}

void GPIO_Init()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	
	GPIOC->MODER &= 0x0000FFFF;
	GPIOC->MODER |= 0x55550000;
	
	GPIOC->OTYPER |= 0x00000000;
	
	GPIOC->OSPEEDR |= 0xFFFF0000; 
	
	GPIOC->ODR = 0xFF00;
}
void SysTick_Handler()
{
	static unsigned char Flow;
	
	if(++Flow >= 8)Flow = 0;
	GPIOC->ODR |= 0XFF00;
	GPIOC->BRR = 1 << (Flow + 8);
}
int main()
{
	SystemCoreClockUpdate();
	Systick_Init();
//	SysTick_Config(SystemCoreClock-1);
	GPIO_Init();
	
	while(1)
	{
//		GPIOC->ODR = 0x5500;
	}
}
