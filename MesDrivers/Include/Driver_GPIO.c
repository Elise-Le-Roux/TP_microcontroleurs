#include "Driver_GPIO.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) {
	char Pin = GPIOStructPtr->GPIO_Pin;
	char Conf = GPIOStructPtr->GPIO_Conf;
	
	if (GPIOStructPtr->GPIO == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;
	if (GPIOStructPtr->GPIO == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
	if (GPIOStructPtr->GPIO == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	if (GPIOStructPtr->GPIO == GPIOD) RCC->APB2ENR |= RCC_APB2ENR_IOPDEN ;
		
	if ( Pin <= 7) {
		GPIOStructPtr->GPIO->CRL &= ~(0xF << 4*Pin); 
		GPIOStructPtr->GPIO->CRL |= (Conf << 4*Pin);
	}
	else {
		GPIOStructPtr->GPIO->CRH &= ~(0xF << 4*(Pin % 8)); 
		GPIOStructPtr->GPIO->CRH |= (Conf << 4*(Pin % 8));
	}
}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	if (GPIO->IDR & (0x1 << GPIO_Pin)) return 1;
	else return 0;
}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->BSRR |= (0x1 << GPIO_Pin);
}

void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->BRR |= (0x1 << GPIO_Pin);
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	if (MyGPIO_Read(GPIO, GPIO_Pin)) {
		MyGPIO_Reset(GPIO, GPIO_Pin);
	}
	else {
		MyGPIO_Set(GPIO, GPIO_Pin);
	}
}
