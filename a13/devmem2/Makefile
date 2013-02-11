#arm-linux-gnueabi-gcc --static -o main_dynamic main.c
CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
#OBJS=devmem2.o
all: $(OBJS)
	$(CC) --static -o devmem2 devmem2.c
clean:
	$(RM) -f devmem2 $(OBJS)
