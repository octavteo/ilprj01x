/*
	https://stackoverflow.com/questions/15807846/ioctl-linux-device-driver?
	https://github.com/torvalds/linux/blob/master/include/uapi/linux/i2c-dev.h

	Test - ADS1110 
*/

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port


int main (int argc, char** argv)
{
	
	int file_i2c;
	int length;
	unsigned char buffer[2] = {0};


	//----- OPEN THE I2C BUS -----
	char *filename = (char*)"/dev/i2c-1";
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the i2c bus");
		return;
	}

	int addr = 1001xxx TODO: RUN PING TEST TO DETERMINE ADDR!
	
	if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		// check errno to see what went wrong
		return;
	}


	//----- READ BYTES -----
	length = 2; //<<< Number of bytes to read
	int try = 0;
	while(1)
	{
		
		if (read(file_i2c, buffer, length) != length)
		{
			//ERROR HANDLING: i2c transaction failed
			try++;
			sleep(0.001);
			if ( try > 1000 )
			{
				printf("Timeout: failed to read from the i2c bus.\n");
				return -1;
			}
		}
		else
		{
			printf("%.2x%.2x\n", buffer[0],buffer[1]);
		}
	}

	return 0;
}