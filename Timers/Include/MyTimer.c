#include "MyTimer.h"

void (* IT_function ) ( void ) ; /* Pointeur de fonction */


void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	
	Timer->Timer->PSC = Timer->PSC; // Réglage de la période du Timer
	Timer->Timer->ARR = Timer->ARR; 
	
	if (Timer->Timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ; // Active l'horloge locale du périphérique
	if (Timer->Timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
	if (Timer->Timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;
	if (Timer->Timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;
	
	Timer->Timer->CR1 |=  (1 << 0); // Active le compteur
}


void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio , void (* IT_function ) ( void ) ) {
	char num_IT;
	
	if (Timer == TIM1) num_IT = 25;        // Sélectionne le numéro d'interruption en fonction du timer
	else if (Timer == TIM2) num_IT = 28;
	else if (Timer == TIM3) num_IT = 29;
	else if (Timer == TIM4) num_IT = 30;
	
	Timer->DIER |= (1 << 0); // Valide l'envoi d'une demande d'interruption
	NVIC->IP[num_IT] |= (Prio << 4); // Fixe la priorité de l'interruption dans le NVIC
	NVIC->ISER[0] |= (1 << num_IT); // Autorise la prise en compte de l'interruption dans le NVIC
}



/********************************************
****              HANDLERS               ****
********************************************/

void TIM1_UP_IRQHandler ( void )
{
	TIM1->SR &= ~(1 << 0); // Remet à 0 le flag d'interruption
}


void TIM2_IRQHandler ( void )
{
	TIM2->SR &= ~(1 << 0);
}


void TIM3_IRQHandler ( void )
{
	TIM3->SR &= ~(1 << 0);
}


void TIM4_IRQHandler ( void )
{
	TIM4->SR &= ~(1 << 0);
}
