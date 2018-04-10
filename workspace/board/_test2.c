/*
	https://hackaday.io/project/17066-c-gpio-library-for-raspberry-pi/log/53420-damned-rpi3

	Test ADS8344 
*/

#include "PI_GPIO.c"

#define ADS8344_SDI xxxxxxx		// Serial Data In  (for ADC, out for PI)
#define ADS8344_SDO xxxxxxx		// Serial Data Out
#define ADS8344_CS	xxxxxxx		// Chip Select

int main (int argc, char** argv)
{
	
	PI_GPIO_config(PI_IN, ADS8344_SDO);
	PI_GPIO_config(PI_OUT, ADS8344_SDI);
	PI_GPIO_config(PI_OUT, ADS8344_CS);
	
	
	
}