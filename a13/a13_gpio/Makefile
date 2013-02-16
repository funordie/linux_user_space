#arm-linux-gnueabi-gcc --static -o main_dynamic main.c
CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
all: $(OBJS)
	$(CC) -g --static -o a13_gpio_user main.c
clean:
	$(RM) -f a13_gpio_user $(OBJS)

