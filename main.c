/*
 * File        : main.c
 * Description : This file includes keypad test application for Atmega32
 *               it display pressed key on LCD
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 2/9/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */

#include "LSTD_Types.h"
#include "LUTILS.h"
#include "LDELAY_Interface.h"
#include "MDIO_Interface.h"
#include "HKPD_Interface.h"
#include "HLCD_Interface.h"


int main(void)
{
	/*global variables*/
	u8 APP_u8KeypadButtonValue = 0;
	
	/*initialize Keypad at PORTB*/
	HKPD_voidInitializeKeypad();
	/*initialize LCD*/
	HLCD_voidInitializeLCD();
	
	/*Display fixed string*/
	HLCD_voidCursorDisplayOnOff(HLCD_OFF);
	HLCD_voidCursorBlinkOnOff(HLCD_OFF);
	HLCD_voidDisplayString("Pressed Char:",HLCD_STRING);
	
	while (1) 
    {
		/*read pressed key*/
		APP_u8KeypadButtonValue = HKPD_u8GetPressedKey();
		/*display pressed keys*/
		HLCD_voidSelectLine(HLCD_LINE2); 
		HLCD_voidDisplayChar(APP_u8KeypadButtonValue);
		LDelay_voidDelay_ms(10);
		
    }/*end of infinite loops*/
	
}/*end of main()*/

