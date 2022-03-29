#include "I2C_Scanner.h"

void setup() {
  
	// Serial Communication Start
	Serial.begin(115200);

	// Start Console
	Terminal.Begin(Serial);

	// Draw Table
	Terminal.I2C_Scanner_Table();

	// Start I2C
	Wire.begin();

}

void loop() {  
  
	// Scan Device
	I2C_Scanner.Device_Scan();

	// Multiplexer Set
	if (Serial.available() > 0) {
	
		// Serial Console Command Read
		uint16_t Key = Serial.read();

		// Terminal Beep
		Terminal.Beep();

		// Handle Command
		switch (Key) {
		case '0':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 0);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '1':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 1);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '2':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 2);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '3':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 3);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '4':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 4);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '5':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 5);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '6':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 6);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '7':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 7);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		case '8':
			I2C.Set_Multiplexer(__I2C__TCA9548__Addr__, 8);
			I2C_Scanner.Clear_Sensor_List();
			break;		
		default:
			break;
		}

	}

	// Loop Delay
	delay(500);

}
