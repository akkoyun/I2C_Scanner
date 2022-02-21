/* *******************************************************************************
 *  Copyright (C) 2014-2022 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: I2C Device Scannner
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *
 *********************************************************************************/

#ifndef __I2C_Scanner__
#define __I2C_Scanner__

// Define Library Structures
#include <I2C_Scanner_Defination.h>

class _I2C_Scanner {

	public:

		bool Draw_Table(void);
		bool Device_Scan(void);

	private:
	
};

extern _I2C_Scanner I2C_Scanner;

#endif /* defined(__I2C_Scanner__) */
