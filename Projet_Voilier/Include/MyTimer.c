#include "MyTimer.h"

void (* PtrF ) ( void ) ;  /* déclaration d’un pointeur de fonction */


void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	
	if (Timer->Timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ; // Active l'horloge locale du périphérique
	if (Timer->Timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
	if (Timer->Timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;
	if (Timer->Timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;
	
	Timer->Timer->PSC = Timer->PSC; // Réglage de la période du Timer
	Timer->Timer->ARR = Timer->ARR; 
	
	Timer->Timer->CR1 |=  (1 << 0); // Active le compteur
}


void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio , void (* IT_function ) ( void ) ) {
	char num_IT;
	
	PtrF = IT_function; /* affectation du pointeur */
	
	if (Timer == TIM1) num_IT = 25;        // Sélectionne le numéro d'interruption en fonction du timer
	else if (Timer == TIM2) num_IT = 28;
	else if (Timer == TIM3) num_IT = 29;
	else if (Timer == TIM4) num_IT = 30;
	
	Timer->DIER |= (1 << 0); // Valide l'envoi d'une demande d'interruption
	NVIC->IP[num_IT] |= (Prio << 4); // Fixe la priorité de l'interruption dans le NVIC
	NVIC->ISER[0] |= (1 << num_IT); // Autorise la prise en compte de l'interruption dans le NVIC
	
}


void MyTimer_PWM( TIM_TypeDef * Timer , char Channel ) {
	if (Channel == 1) {
		Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;                   // Mode 1 de la PWM
		Timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
		Timer->CCER |= TIM_CCER_CC1E;                        // Validation de la sortie du canal
	}
	else if (Channel == 2) {
		Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
		Timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
		Timer->CCER |= TIM_CCER_CC2E;
	}
	else if (Channel == 3) {
		Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0;
		Timer->CCMR2 |= TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;
		Timer->CCER |= TIM_CCER_CC3E;
	}
	else if (Channel == 4) {
		Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0;
		Timer->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;
		Timer->CCER |= TIM_CCER_CC4E;
	}
}	
	
void Set_Duty_Cycle (TIM_TypeDef * Timer, char Channel, char Duty_Cycle) {
	if (Channel == 1) {
		Timer->CCR1 = (int) (Timer->ARR)*Duty_Cycle/100;
	}
	else if (Channel == 2) {
		Timer->CCR2 = (int) (Timer->ARR)*Duty_Cycle/100;
	}
	else if (Channel == 3) {
		Timer->CCR3 = (int) (Timer->ARR)*Duty_Cycle/100;
	}
	else if (Channel == 4) {
		Timer->CCR4 = (int) (Timer->ARR)*Duty_Cycle/100;
	}
}




/********************************************
****              HANDLERS               ****
********************************************/

void TIM1_UP_IRQHandler ( void )
{
	TIM1->SR &= ~(1 << 0); // Remet à 0 le flag d'interruption
	if (PtrF != 0)
		(*PtrF) (); /* appel indirect de la fonction */
}


void TIM2_IRQHandler ( void )
{
	//TIM2->SR &= ~(1 << 0);
	TIM2->SR &= ~TIM_SR_UIF;
	if (PtrF != 0)
		(*PtrF) (); /* appel indirect de la fonction */
}


void TIM3_IRQHandler ( void )
{
	TIM3->SR &= ~(1 << 0);
	if (PtrF != 0)
		(*PtrF) (); /* appel indirect de la fonction */
}


void TIM4_IRQHandler ( void )
{
	TIM4->SR &= ~(1 << 0);
	if (PtrF != 0)
		(*PtrF) (); /* appel indirect de la fonction */
}
