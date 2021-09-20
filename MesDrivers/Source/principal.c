#include "Driver_GPIO.h"


int main ( void ) {
	
	// Definitions
	MyGPIO_Struct_TypeDef GPIO_Struct_PA5;
	MyGPIO_Struct_TypeDef GPIO_Struct_PC13;
	
	// Configuration PA.5 en output push-pull 2MHz
	GPIO_Struct_PA5.GPIO = GPIOA;
	GPIO_Struct_PA5.GPIO_Pin = 5;
	GPIO_Struct_PA5.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&GPIO_Struct_PA5);
	
	// Configuration PC.13 en floating input
	GPIO_Struct_PC13.GPIO = GPIOC;
	GPIO_Struct_PC13.GPIO_Pin = 13;
	GPIO_Struct_PC13.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct_PC13);
	
	
do
{
	if( !(MyGPIO_Read(GPIO_Struct_PC13.GPIO, GPIO_Struct_PC13.GPIO_Pin)) ) { // Si le BP est allumé (polarité inverse)
		// on allume la LED 
		MyGPIO_Set(GPIO_Struct_PA5.GPIO, GPIO_Struct_PA5.GPIO_Pin);
	}
	else
	{
		// sinon on éteint la LED
		MyGPIO_Reset(GPIO_Struct_PA5.GPIO, GPIO_Struct_PA5.GPIO_Pin);
	}
}while (1) ;
}

