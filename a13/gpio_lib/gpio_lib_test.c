#include <stdio.h>
#include "gpio_lib.h"

#define DELAY 32768000

int main()
{
	volatile int i,j,k, ret;

	ret = sunxi_gpio_init();
	if(ret) {
		printf("sunxi_gpio_init ERROR\n");
		return -1;
	}

	sunxi_gpio_set_cfgpin(SUNXI_GPG(9), SUNXI_GPIO_OUTPUT);

	for(i = 0; i < 100; i++ ) {
		printf("sunxi_gpio_output(SUNXI_GPG(9), 0) :%d\n", i);
		sunxi_gpio_output(SUNXI_GPG(9), 0);

		for(j = 0; j < DELAY; j++ ) {
			k = j;
		}

		printf("sunxi_gpio_output(SUNXI_GPG(9), 1) :%d\n", i);
		sunxi_gpio_output(SUNXI_GPG(9), 1);

		for(j = 0; j < DELAY; j++ ) {
			k = j;
		}
	}

	return 0;
}
