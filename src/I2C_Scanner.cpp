/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: I2C Device Scanner
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *********************************************************************************/

#include <I2C_Scanner.h>

bool _I2C_Scanner::Device_Scan(void) {

	// Declare Address Variable
	uint8_t _Address = 0x00;

	// Set Sensor Name Row
	uint8_t _Row = 24;

	for (uint8_t j = 6; j < 21; j = j + 2) {

		// Control Device Line 1
		for (uint8_t i = 11; i < 121; i = i +7) {

			// Handle Reserved
			if (_Address > 0x03 and _Address < 0x78) {

				// Control Device
				if (I2C.Control_Device(_Address)) {

					Terminal.Text(j,i,CYAN,String("0x"));
					Terminal.Text(j,i+2,CYAN,String(_Address,HEX));

					// Print Sensor Name
					if (_Address == I2C.TCA9548.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.TCA9548.I2C_Address, HEX) + " - " + String(I2C.TCA9548.Sensor_Name) + " - " + String(I2C.TCA9548.Sensor_Vendor) + " (" + String(I2C.TCA9548.Sensor_Type) + ")");
						_Row++;
					}
					if (_Address == I2C.RV3028C7.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.RV3028C7.I2C_Address, HEX) + " - " + String(I2C.RV3028C7.Sensor_Name) + " - " + String(I2C.RV3028C7.Sensor_Vendor) + " (" + String(I2C.RV3028C7.Sensor_Type) + ")"); 
						_Row++;
					}
					if (_Address == I2C.DS28C.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.DS28C.I2C_Address, HEX) + " - " + String(I2C.DS28C.Sensor_Name) + " - " + String(I2C.DS28C.Sensor_Vendor) + " (" + String(I2C.DS28C.Sensor_Type) + ")"); 
						_Row++;
					}
					if (_Address == I2C.HDC2010.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.HDC2010.I2C_Address, HEX) + " - " + String(I2C.HDC2010.Sensor_Name) + " - " + String(I2C.HDC2010.Sensor_Vendor) + " (" + String(I2C.HDC2010.Sensor_Type) + ")"); 
						_Row++;
					}
					if (_Address == I2C.MAX17055.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.MAX17055.I2C_Address, HEX) + " - " + String(I2C.MAX17055.Sensor_Name) + " - " + String(I2C.MAX17055.Sensor_Vendor) + " (" + String(I2C.MAX17055.Sensor_Type) + ")"); 
						_Row++;
					}
					if (_Address == I2C.BQ24298.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.BQ24298.I2C_Address, HEX) + " - " + String(I2C.BQ24298.Sensor_Name) + " - " + String(I2C.BQ24298.Sensor_Vendor) + " (" + String(I2C.BQ24298.Sensor_Type) + ")"); 
						_Row++;
					}
					if (_Address == I2C.SHT21.I2C_Address) {
						Terminal.Text(_Row, 2, CYAN, "0x" + String(I2C.SHT21.I2C_Address, HEX) + " - " + String(I2C.SHT21.Sensor_Name) + " - " + String(I2C.SHT21.Sensor_Vendor) + " (" + String(I2C.SHT21.Sensor_Type) + ")"); 
						_Row++;
					}					

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
bool _I2C_Scanner::Clear_Sensor_List(void) {

	Terminal.Text(24,2,CYAN,String("                                "));
	Terminal.Text(25,2,CYAN,String("                                "));
	Terminal.Text(26,2,CYAN,String("                                "));
	Terminal.Text(27,2,CYAN,String("                                "));
	Terminal.Text(28,2,CYAN,String("                                "));
	Terminal.Text(29,2,CYAN,String("                                "));
	Terminal.Text(30,2,CYAN,String("                                "));

}

// Define Library Class
_I2C_Scanner I2C_Scanner;

// 1903