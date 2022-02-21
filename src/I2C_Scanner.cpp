/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: I2C Device Scanner
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *********************************************************************************/

#include <I2C_Scanner.h>

bool _I2C_Scanner::Draw_Table(void) {

    // Draw Console Table
	for (uint8_t i = 1; i <= 23; i = i + 2) {Terminal.Draw_Horizontal_Divider(i, 1, 120, false);}
    Terminal.Draw_Vertical_Divider(1, 1, 22);
	for (uint8_t i = 9; i <= 120; i = i + 7) {Terminal.Draw_Vertical_Divider(3, i, 18);}
    Terminal.Draw_Vertical_Divider(1, 121, 22);

	// Draw Corners
    Terminal.Set_Cursor(1,1); Serial.print("┌");
    Terminal.Set_Cursor(1,121); Serial.print("┐");
    Terminal.Set_Cursor(23,1); Serial.print("└");
    Terminal.Set_Cursor(23,121); Serial.print("┘");

	// Draw T
	for (uint8_t i = 3; i <= 21; i = i + 2) {Terminal.Set_Cursor(i,1); Serial.print("├");}
	for (uint8_t i = 3; i <= 21; i = i + 2) {Terminal.Set_Cursor(i,121); Serial.print("┤");}
	
	// Draw CrosSection
	for (uint8_t i = 5; i <= 19; i = i + 2) {for (uint8_t j = 9; j <= 120; j = j + 7) {Terminal.Set_Cursor(i,j); Serial.print("┼");}}
	
	// Write Text
	Terminal.Print_Box_Title(1,1,60,"I2C DEVICE EXPLORER");
	Terminal.Text(22,3,WHITE,"Total connected device :");
	Terminal.Text(22,86,WHITE,"Current Mux Channel [0-8] :");
	Terminal.Text(24,100,WHITE,"github.com/akkoyun");

	// Print headers
	uint8_t _C = 0;
	for (uint8_t i = 6; i <= 21; i = i + 2) {
		Terminal.Set_Cursor(i,3); Serial.print("0x");
		Terminal.Set_Cursor(i,5); Serial.print(_C);
		Terminal.Set_Cursor(i,6); Serial.print("_");
		_C++;
	}
	uint8_t _R = 0;
	for (uint8_t i = 11; i <= 121; i = i + 7) {
		Terminal.Set_Cursor(4,i); Serial.print("0x_");
		Terminal.Set_Cursor(4,i+3); Serial.print(_R, HEX);
		_R++;
	}

}
bool _I2C_Scanner::Device_Scan(void) {

	// Declare Address Variable
	uint8_t _Address = 0x00;

	for (uint8_t j = 6; j < 21; j = j + 2) {

		// Control Device Line 1
		for (uint8_t i = 11; i < 121; i = i +7) {

			// Handle Reserved
			if (_Address > 0x03 and _Address < 0x78) {

				// Control Device
				if (I2C.Control_Device(_Address)) {

					Terminal.Text(j,i,CYAN,String("0x"));
					Terminal.Text(j,i+2,CYAN,String(_Address,HEX));

				} else {

					Terminal.Text(j,i,WHITE,"----");

				}

			}

			// Handle Address
			_Address++;

		}

	}	

	// Print Mux Channel
	Terminal.Text(22,115,CYAN,String(I2C._Multiplexer_Current_Channel));

}

// Define Library Class
_I2C_Scanner I2C_Scanner;

// 1903