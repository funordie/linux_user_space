#include "gpio.h"
#include "gpio.c"

int main()
{
   gpio_set_value(SUNXI_GPG(9), 1); // set pg9

   return 0;
}
