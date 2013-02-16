#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {

	int fd, res, port_index;
	unsigned long ulData;
	ssize_t  bytes_read;
	char * port;

	if(argc != 2) {
		printf("usage: [port] \n");
		return -1;
	}

	port = argv[1];

	port_index = strcmp(port, "B");

	printf("read port_index:%d\n", port_index+1);

	if(port_index < 0 && port_index > 5) {
		printf("Please enter port A to G\n");
		return -1;
	}

	fd = open("/dev/a13_gpio_value", O_RDWR);
	if(fd < 0) printf("error: cannot open file '/dev'/a13_gpio_value");

	//driver read memory from port A, user app read memory from port B
	res = lseek(fd, (port_index+1)*sizeof(unsigned long), SEEK_SET);

	bytes_read = read(fd, &ulData, sizeof(unsigned long));

	printf("read data bytes_read:%d data:%#lx\n", bytes_read, ulData);

	close(fd);
return 0;
}
