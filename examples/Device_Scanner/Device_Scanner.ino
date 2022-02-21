#include "I2C_Scanner.h"

void setup() {
  
	// Serial Communication Start
	Serial.begin(115200);

	// Start Console
	Terminal.Begin(Serial);

	// Draw Table
	I2C_Scanner.Draw_Table();

	// Start I2C
	Wire.begin();

}

void loop() {  
  
	// Scan Device
	I2C_Scanner.Device_Scan();

	// Multiplexer Set
	if (Serial.available() > 0) {
	
		uint16_t Key = Serial.read();

		// Terminal Beep
		Terminal.Beep();

		switch (Key) {
		case '0':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 0);
			break;		
		case '1':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 1);
			break;		
		case '2':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 2);
			break;		
		case '3':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 3);
			break;		
		case '4':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 4);
			break;		
		case '5':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 5);
			break;		
		case '6':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 6);
			break;		
		case '7':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 7);
			break;		
		case '8':
			I2C.Set_Multiplexer(__ADDR_TCA9548__, 8);
			break;		
		default:
			break;
		}
	}

	// Loop Delay
	delay(500);

}
