#include "Driver_GPIO.h"
#include "stm32f10x.h"

int main ( void ) {
	
	TIM2->PSC = 0x1770; // 6000
	TIM2->ARR = 0x1770;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 = TIM2->CR1 | ( 1 << 0);
do
{
}while (1) ;
}

