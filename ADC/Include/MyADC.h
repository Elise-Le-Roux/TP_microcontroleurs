#ifndef MYADC_H
#define MYADC_H
#include "stm32f10x.h"


/*
*****************************************************************************************
* @brief
* @param -> - char input_channel : de 0 à 17
* @Note -> 
*************************************************************************************************
*/
void MyADC_Init ( char input_channel);



/*
*****************************************************************************************
* @brief
* @param -> - char input_channel : de 0 à 17
* @Note -> Débute la conversion et retourne son résultat.
	La fonction MyADC_Init doit avoir été lancée au préalable.
*************************************************************************************************
*/
int convert_single(void);

#endif
