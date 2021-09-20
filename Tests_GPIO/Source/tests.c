#include "Driver_GPIO.h"

int main ( void ) {
	
	// Def
	MyGPIO_Struct_TypeDef GPIO_Struct;
	
	// Tests port A
	GPIO_Struct.GPIO = GPIOA;
	
	// Pin 0
	GPIO_Struct.GPIO_Pin = 0;
	
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullDown;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullUp;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_Analog;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	
	// Pin 8
	GPIO_Struct.GPIO_Pin = 8;
	
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullDown;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullUp;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_Analog;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	// Pin 15
	GPIO_Struct.GPIO_Pin = 15;
	
	GPIO_Struct.GPIO_Conf = In_Floating;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullDown;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_PullUp;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = In_Analog;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = Out_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	GPIO_Struct.GPIO_Conf = AltOut_OD;
	MyGPIO_Init(&GPIO_Struct);
	
	
	// Tests port B
	GPIO_Struct.GPIO = GPIOB;
	MyGPIO_Init(&GPIO_Struct);
	
	
	
	// Tests port C
	GPIO_Struct.GPIO = GPIOC;
	MyGPIO_Init(&GPIO_Struct);
	
	
	
	// Tests port D
	GPIO_Struct.GPIO = GPIOD;
	MyGPIO_Init(&GPIO_Struct);
}
