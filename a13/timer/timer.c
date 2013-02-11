#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "gpio_lib.h"	//gpio library
void timer_handler (int signum)
{
	static unsigned short value;

	//printf ("timer expired %d times\n", ++count);
	sunxi_gpio_output(SUNXI_GPG(9), value);

	if(value) value = 0;
	else value = 1;
}
int main ()
{
	struct sigaction sa;
	struct itimerval timer;
	int ret;
	/* Install timer_handler as the signal handler for SIGVTALRM. */
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &timer_handler;
	sigaction (SIGVTALRM, &sa, NULL);
	/* Configure the timer to expire after 250 msec... */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 250000;
	/* ... and every 250 msec after that. */
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 250000;
	/* Start a virtual timer. It counts down whenever this process is
executing. */
	setitimer (ITIMER_VIRTUAL, &timer, NULL);

	//init gpio
	ret = sunxi_gpio_init();
	if(ret) {
		printf("sunxi_gpio_init ERROR\n");
		return -1;
	}
	sunxi_gpio_set_cfgpin(SUNXI_GPG(9), SUNXI_GPIO_OUTPUT);

	/* Do busy work. */
	while(1);
}
