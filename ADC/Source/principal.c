#include "Driver_GPIO.h"
#include "MyTimer.h"
#include "MyADC.h"
#include "stm32f10x.h"

MyGPIO_Struct_TypeDef GPIO_Struct;

void CallBack ( void )
{
	/* Le code à exécuter pendant l’interruption */
	MyGPIO_Toggle (GPIO_Struct.GPIO, GPIO_Struct.GPIO_Pin) ;
}


int main ( void ) {
	
	int res = 0;
	
	// Configuration du timer
	MyTimer_Struct_TypeDef TIM;
	TIM.Timer = TIM3;
	TIM.ARR = 719; //2000
	TIM.PSC = 0; // 18000
	MyTimer_Base_Init(&TIM);
	
	// Configuration de la diode PA.6
	GPIO_Struct.GPIO = GPIOA;
	GPIO_Struct.GPIO_Pin = 6;
	GPIO_Struct.GPIO_Conf = AltOut_Ppull;
	MyGPIO_Init(&GPIO_Struct);
	
	// PWM à 100kHz avec un rapport cyclique de 0% sur le Timer 3 et le canal 1.
	MyTimer_PWM (TIM3, 1);
	Set_Duty_Cycle(TIM3, 1, 0);
	
	// Configuration de la broche PB.0
	GPIO_Struct.GPIO = GPIOB;
	GPIO_Struct.GPIO_Pin = 0;
	GPIO_Struct.GPIO_Conf = In_Analog;
	MyGPIO_Init(&GPIO_Struct);
	
	MyADC_Init(8);
	
	
	
   
while (1)
{
	res = convert_single(); // conversion
  Set_Duty_Cycle(TIM3, 1, 100 * res / 0xFFF ); // mise à jour de l’intensité de la led
}
}
