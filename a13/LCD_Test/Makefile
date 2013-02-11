#arm-linux-gnueabi-gcc --static -o main_dynamic main.c
CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
all: $(OBJS)
	$(CC) --static -o lcd_test lcd_test.c gpio_lib.c
clean:
	$(RM) -f lcd_test.c $(OBJS)

