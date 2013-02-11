#arm-linux-gnueabi-gcc --static -o main_dynamic main.c
CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
#OBJS=timer_1.o
all: $(OBJS)
	$(CC) --static -o timer_1 timer_1.c gpio_lib.c
clean:
	$(RM) -f timer_1 $(OBJS)

