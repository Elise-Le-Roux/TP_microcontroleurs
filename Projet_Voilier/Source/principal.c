#include "Driver_GPIO.h"
#include "MyTimer.h"
#include "stm32f10x.h"

MyGPIO_Struct_TypeDef GPIO_Struct;

void CallBack ( void )
{
	/* Le code � ex�cuter pendant l�interruption */
	MyGPIO_Toggle (GPIO_Struct.GPIO, GPIO_Struct.GPIO_Pin) ;
}


int mesure_angle ()
{
}


int main ( void ) {
	
// Def
	MyGPIO_Struct_TypeDef GPIO_Struct;
	
	
// Configuration entr�es girouette
	
	// PA6 -- A
	GPIO_Struct.GPIO = GPIOA;
	GPIO_Struct.GPIO_Pin = 6;
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
	// PA7 -- B
	GPIO_Struct.GPIO = GPIOA;
	GPIO_Struct.GPIO_Pin = 7;
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
	// PA5 -- I
	GPIO_Struct.GPIO = GPIOA;
	GPIO_Struct.GPIO_Pin = 5;
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
// Configuration des interruptions girouettes
	
	
do
{
}while (1) ;
}
