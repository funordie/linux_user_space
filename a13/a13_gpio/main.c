#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PORT 6 /* port G */

int main() {

	int fd, res;
	unsigned long ulData;
	unsigned long * dev_pointer;
	ssize_t  bytes_read;

	fd = open("/dev/a13_gpio_value", O_RDWR);
	if(fd < 0) printf("error: cannot open file '/dev'/a13_gpio_value");

	res = lseek(fd, 6*4, SEEK_SET);

	bytes_read = read(fd, &ulData, sizeof(unsigned long));


	printf("read data bytes_read:%d data:%#lx\n", bytes_read, ulData);

	close(fd);
return 0;
}
