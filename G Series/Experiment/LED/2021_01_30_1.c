#include "stm32G4xx.h"

void KeyScan()
{
	static unsigned char key;
	
	key = (GPIOA->IDR & 0x0001) | ((GPIOB->IDR & 0x07) << 1);
	
	GPIOC->BRR |= (key ^ 0x0F) << 8;
	GPIOC->ODR |= key << 8;
}

void Systick_Init(unsigned short Div)
{
	SysTick->LOAD = SystemCoreClock/Div - 1;
	SysTick->CTRL = 0x00000007;
}

void GPIO_Init()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	
	GPIOC->MODER &= 0x0000FFFF;
	GPIOC->MODER |= 0x55550000;
	
	GPIOC->OTYPER |= 0x0000;						//¸´Î»ÖµÎª0
	
	GPIOC->OSPEEDR |= 0xFFFF0000; 
	
	GPIOC->ODR = 0xFF00;
	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
	
	GPIOD->MODER &= 0xFFFFFFCF;
	GPIOD->MODER |= 0x00000010;
	
	GPIOD->OTYPER |= 0X0000;
	
	GPIOD->OSPEEDR |= 0x00000030;
	
	GPIOD->ODR |= 0x0004;
	
	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN|RCC_AHB2ENR_GPIOBEN;
	
	GPIOA->MODER &= 0xFFFFFFFC;
	GPIOB->MODER &= 0xFFFFFFC0;
	
	GPIOA->PUPDR &= 0xFFFFFFFC;
	GPIOB->PUPDR &= 0xFFFFFFC0;
}
void SysTick_Handler()
{
	static unsigned char Flow;
	
	if(++Flow >= 8)Flow = 0;
	
	KeyScan();
//	GPIOC->ODR |= 0XFF00;
//	GPIOC->BRR = 1 << (Flow + 8);
}
int main()
{
	SystemCoreClockUpdate();
	Systick_Init(1000);
//	SysTick_Config(SystemCoreClock-1);
	GPIO_Init();
	
	while(1)
	{
//		GPIOC->ODR = 0x5500;
	}
}
