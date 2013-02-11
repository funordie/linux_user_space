#include "gpio-mmap.h"

int main() {
	int i;
	gpio_map();
	gpio_output(2,1); //bank 2 bit 1 = GPIO65 the LED on board
//	while (1) {
//		GPIO_WRITE_PIN(65,1);
//		GPIO_WRITE_PIN(65,0);
//	}
	for (i = 0; i < 100; i++) {
		printf("gpio 65: 1\n");
		GPIO_WRITE_PIN(65,1);
		printf("gpio 65: 0\n");
		GPIO_WRITE_PIN(65,0);
	}
}
