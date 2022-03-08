/* *******************************************************************************
 *  Copyright (C) 2014-2022 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: I2C Device Scannner
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *********************************************************************************/

#ifndef __I2C_Scanner__
#define __I2C_Scanner__

// Define Arduino Library
#ifndef __Arduino__
#include <Arduino.h>
#endif

// Define I2C Functions Library
#ifndef __I2C_Functions__
#include <I2C_Functions.h>
#endif

// Define Console Library
#ifndef __Console__
#include <Console.h>
#endif

class _I2C_Scanner {

	public:

		bool Device_Scan(void);
		bool Clear_Sensor_List(void);

	private:

};

extern _I2C_Scanner I2C_Scanner;

#endif /* defined(__I2C_Scanner__) */
