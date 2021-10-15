#include "MyADC.h"

void MyADC_Init ( char input_channel ) {
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; // Active l'horloge de l'ADC
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6; // Divise par 6 la fr�quence d'entr�e qui doit �tre < 14 MHz
	ADC1->CR2|= ADC_CR2_ADON; // Active l'ADC
	ADC1->SQR1 &= ADC_SQR1_L; // 1 voie � convertir 
	ADC1->SQR3|= input_channel; // s�lectionne la voie � convertir
	//ADC1->CR2 |= ADC_CR2_CAL; // d�but de la calibration
	//while (ADC1->CR2 & ADC_CR2_CAL); // attente de la fin de la calibration
}

int convert_single(){
    ADC1->CR2 |= ADC_CR2_ADON; // lancement de la conversion
    while(!(ADC1->SR & ADC_SR_EOC) ) {} // attente de la fin de conversion
    ADC1->SR &= ~ADC_SR_EOC; // validation de la conversion
    return ADC1->DR ;//& ~((0x0F) << 12); // retour de la conversion
}
