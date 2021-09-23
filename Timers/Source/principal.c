#include "Driver_GPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"

int main ( void ) {
	
//	TIM2->PSC = 0x1770; // 6000
//	TIM2->ARR = 0x1770;
//	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // Clock enable
//	TIM2->CR1 |=  (1 << 0); // Counter enable
	
	
	MyTimer_Struct_TypeDef TIM;
	TIM.Timer = TIM2;
	TIM.ARR = 0x1770;
	TIM.PSC = 0x1770;
	
	MyTimer_Base_Init(&TIM);
	//MyTimer_Base_Stop(TIM.Timer);
	
	MyTimer_ActiveIT(TIM2, 1);
do
{
}while (1) ;
}
