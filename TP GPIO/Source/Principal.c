

#include "stm32f10x.h"


int main ( void )
{
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;

	// Configuration PA.5 en output push-pull 2MHz
	GPIOA->CRL &= ~(0xF << 4*5); 
	GPIOA->CRL |= (0x2 << 4*5);
	
	// Configuration PA.5 en output open drain 2MHz
//	GPIOA->CRL &= ~(0xF << 4*5); 
//	GPIOA->CRL |= (0x6 << 4*5);
	
	// Configuration PC.13 en floating input
	GPIOC->CRH &= ~(0xF << 4*5);
	GPIOC->CRH |= (0x4 << 4*5);
	
	
do
{
	if( !(GPIOC->IDR & (0x01 << 13)) ) { // Si le BP est allumé (polarité inverse)
		// on allume la LED 
		GPIOA->BSRR |= (0x1 << 5);
	}
	else
	{
		// sinon on éteint la LED
		GPIOA->BRR |= (0x1 << 5);
	}
}while (1) ;
}
