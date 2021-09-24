#include "Driver_GPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"

MyGPIO_Struct_TypeDef GPIO_Struct;

void CallBack ( void )
{
	/* Le code à exécuter pendant l’interruption */
	MyGPIO_Toggle (GPIO_Struct.GPIO, GPIO_Struct.GPIO_Pin) ;
}


int main ( void ) {
	
//	TIM2->PSC = 0x1770; // 6000 
//	TIM2->ARR = 0x1770; 
//	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // Clock enable
//	TIM2->CR1 |=  (1 << 0); // Counter enable
	
	// Configuration du timer
	MyTimer_Struct_TypeDef TIM;
	TIM.Timer = TIM1;
	TIM.ARR = 2000; 
	TIM.PSC = 18000; 
	
	//TIM2->CR1 |= TIM_CR1_URS;
	
	// Configuration de la diode PA.5
	GPIO_Struct.GPIO = GPIOA;
	GPIO_Struct.GPIO_Pin = 5;
	GPIO_Struct.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	MyTimer_Base_Init(&TIM);
	
	MyTimer_ActiveIT(TIM1, 1, CallBack);
	
	
do
{
}while (1) ;
}
