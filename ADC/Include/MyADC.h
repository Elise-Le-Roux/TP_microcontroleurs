#ifndef MYADC_H
#define MYADC_H
#include "stm32f10x.h"


/*
*****************************************************************************************
* @brief
* @param -> - char input_channel : de 0 � 17
* @Note -> 
*************************************************************************************************
*/
void MyADC_Init ( char input_channel);



/*
*****************************************************************************************
* @brief
* @param -> - char input_channel : de 0 � 17
* @Note -> D�bute la conversion et retourne son r�sultat.
	La fonction MyADC_Init doit avoir �t� lanc�e au pr�alable.
*************************************************************************************************
*/
int convert_single(void);

#endif
