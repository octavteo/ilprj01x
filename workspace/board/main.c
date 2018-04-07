#define PI_GPIO_ERR  // errno.h
#include "PI_GPIO.c"

#define PI_IN  (4)
#define PI_OUT (25)

int main(int argc, char *argv[]) {
	
  PI_GPIO_config(PI_IN,  BCM_GPIO_IN);
  PI_GPIO_config(PI_OUT, BCM_GPIO_OUT);

  while (1) {
    printf("GPIO4=%d\n", GPIO_LEV_N(PI_IN));
    if (GPIO_LEV_N(PI_IN))
      GPIO_SET_N(PI_OUT);
    else
      GPIO_CLR_N(PI_OUT);
  }
}