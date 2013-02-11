#arm-linux-gnueabi-gcc --static -o main_dynamic main.c
CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
OBJS=timer.o
all: $(OBJS)
	$(CC) --static -o timer timer.c gpio_lib.c
clean:
	$(RM) -f timer $(OBJS)

