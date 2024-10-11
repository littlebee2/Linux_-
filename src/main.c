#include <stdio.h>
#include <unistd.h>
#include "can.h"
#include "can_anayse.h"

int dev_led_fd;
int main(void)
{
	printf("开始初始化CAN设备\r\n");
	can_rx_tx_init();
	while(1)
	{
		can_handler();
		//msleep(50);
	}
}