#include <stdio.h>
#include "gpio_lib.h"

int init_lcd_pin_direction() {
//	GPIO2			LCD
//	1 	+5V 	-> 	2 VDD
//	2 	Ground 	->	1 GND
//
//	3 	+3.3V	EMPTY
//	4 	Ground	EMPTY
//
//
//	5 	PB0 (TWI0-SCK)	->	4 RS
//	6 	PG11 (USBH_EN)	->	5 R/W
//	7 	PB1 (TWI0-SDA) 	->	6 E
//
//	8 	PG10 (VGA_DIS)	->	7 DB0
//	10 	PG9 (LED1)		->	8 DB1
//	11 	PB3 			->  9 DB2
//	12 	PE11			->  10 DB3
//	13 	PB4 			->  11 DB4
//	14 	PE10			->  12 DB5
//	16 	PE9				->  13 DB6
//	18 	PE8				->  14 DB7

	//	9 	PB2 (PWM0) 		ERROR
	//	15 	PB10 			ERROR
	//	17 	PB15 (TWI1-SCK) ERROR
	int ret;

	//init gpio
	ret = sunxi_gpio_init();
	if(ret) {
		printf("sunxi_gpio_init ERROR\n");
		return -1;
	}
/*	//RS, R/W, E
	sunxi_gpio_set_cfgpin(SUNXI_GPB(0), SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPG(11), SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPB(1), SUNXI_GPIO_OUTPUT);

	//DB0 - DB7
	sunxi_gpio_set_cfgpin(SUNXI_GPG(10), SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPG(9),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPB(3),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPE(11), SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPB(4),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPE(10), SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPE(9),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPE(8),  SUNXI_GPIO_OUTPUT);
*/
	sunxi_gpio_set_cfgpin(SUNXI_GPA(0),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPA(1),  SUNXI_GPIO_OUTPUT);

	sunxi_gpio_set_cfgpin(SUNXI_GPB(0),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPB(1),  SUNXI_GPIO_OUTPUT);

	sunxi_gpio_set_cfgpin(SUNXI_GPI(0),  SUNXI_GPIO_OUTPUT);
	sunxi_gpio_set_cfgpin(SUNXI_GPI(1),  SUNXI_GPIO_OUTPUT);

	sunxi_gpio_set_cfgpin(SUNXI_GPG(9),  SUNXI_GPIO_OUTPUT);
	return 0;
}

void lcd_set_RS(unsigned uValue) {
	sunxi_gpio_output(SUNXI_GPB(0), uValue);
}
void lcd_set_RW(unsigned uValue) {
	sunxi_gpio_output(SUNXI_GPG(11), uValue);
}
void lcd_set_E(unsigned uValue) {
	sunxi_gpio_output(SUNXI_GPB(1), uValue);
}

void lcd_set_data(unsigned uValue) {

	sunxi_gpio_output(SUNXI_GPG(10), uValue & 0x01);
	sunxi_gpio_output(SUNXI_GPG(9),  uValue & 0x02);
	sunxi_gpio_output(SUNXI_GPB(3),  uValue & 0x04);
	sunxi_gpio_output(SUNXI_GPE(11), uValue & 0x08);
	sunxi_gpio_output(SUNXI_GPB(4),  uValue & 0x10);
	sunxi_gpio_output(SUNXI_GPE(10), uValue & 0x20);
	sunxi_gpio_output(SUNXI_GPE(9),  uValue & 0x40);
	sunxi_gpio_output(SUNXI_GPE(8),  uValue & 0x80);
}
void delay(unsigned Tick) {
	volatile unsigned i, k, delay;
	delay = Tick*100000;

	for(i=0; i < delay; i++) {
		k++;
	}
}
int main(int argc, const char* argv[] ) {

	//30ms delay
	delay(30);

	init_lcd_pin_direction();
	delay(30);
/*
	lcd_set_RS(0);
	lcd_set_RW(0);
	lcd_set_E(0);
	lcd_set_data(0x3A);

	lcd_set_E(1);
	delay(30);
	lcd_set_E(0);

	lcd_set_data(0x0F);

	lcd_set_E(1);
	delay(30);
	lcd_set_E(0);
*/
	int pin;
	char *port;
	int i, k, val;
	val = 0;

	printf("app startup\n");
	printf("argv[1]:%s  argv[2]:%s\n", argv[1], argv[2]);

	port = argv[1];
	pin = atoi(argv[2]);

	printf("port:%s\n",port);
	printf("pin:%d\n",pin);

	if(!strcmp(port, "G")) {
		while(1) {
			//sunxi_gpio_output(SUNXI_GPG(9),  0);
			sunxi_gpio_output(SUNXI_GPG(pin),  0);
			delay(3000);
			//sunxi_gpio_output(SUNXI_GPG(9),  1);
			sunxi_gpio_output(SUNXI_GPG(pin),  1);
			delay(3000);
		};
	}
	else if(!strcmp(port, "A")) {
		while(1) {
			sunxi_gpio_output(SUNXI_GPA(pin),  0);
			//sunxi_gpio_output(SUNXI_GPA(pin),  0);
			delay(3000);
			sunxi_gpio_output(SUNXI_GPA(pin),  1);
			//sunxi_gpio_output(SUNXI_GPA(pin),  1);
			delay(3000);
		};
	}
	else if(!strcmp(port, "B")) {
		while(1) {
			sunxi_gpio_output(SUNXI_GPB(pin),  0);
			//sunxi_gpio_output(SUNXI_GPA(pin),  0);
			delay(3000);
			sunxi_gpio_output(SUNXI_GPB(pin),  1);
			//sunxi_gpio_output(SUNXI_GPA(pin),  1);
			delay(3000);
		};
	}
	else if(!strcmp(port, "I")) {
		while(1) {
			sunxi_gpio_output(SUNXI_GPI(pin),  0);
			//sunxi_gpio_output(SUNXI_GPA(pin),  0);
			delay(3000);
			sunxi_gpio_output(SUNXI_GPI(pin),  1);
			//sunxi_gpio_output(SUNXI_GPA(pin),  1);
			delay(3000);
		};
	}
	return 0;
}
