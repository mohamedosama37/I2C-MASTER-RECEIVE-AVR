/*
 * main.c
 *
 *  Created on: May 23, 2019
 *      Author: Marna
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "I2C_private.h"
#define SREG   *((u8*)0x5f)
#include "I2C_interface.h"
u8 arr[5];

void main ()
{

	DIO_u8SetPinDir (22 , 1);
	DIO_u8SetPinDir (23 , 1);


	SREG  |=0x80;
	inital_master mstr = {NORMALMODE ,0x07,ENABLE_INTERRUPT};
	I2C_initinal ( &mstr);
	callbkfn ( I2C_SendStop );
 	I2C_MasterReadAsynchsen ( arr ,5 , 0xff);
	 while (1)
	 {


	 }


}
