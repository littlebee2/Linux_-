#include "ledApp.h"
#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int dev_led_fd;
#define DEV_LED		"/dev/gpioled"
pthread_mutex_t mutex_led;
pthread_cond_t cond_led;

Struct_LedType led;

void *pthread_led (void *arg)
{
	int retvalue;
	if ((dev_led_fd = open (DEV_LED, O_RDWR)) < 0)
	{
		printf ("Cann't open file /dev/gpioled\n");
		exit (-1);
	}
	printf ("pthread_led open success\n");
	while (1)
	{
		pthread_mutex_lock (&mutex_led);//获取互斥锁
		pthread_cond_wait (&cond_led, &mutex_led);//在等待条件变量时，阻塞线程并释放互斥锁。
		printf ("[thread_led] is wake up\n");
		if(led.mode == LED_OPEN)
			retvalue = write(dev_led_fd, 1, 1);
		else
			retvalue = write(dev_led_fd,0, 1);
		if(retvalue < 0)
		{
			printf("LED Control Error\n");
			close(dev_led_fd);
			return -1;
		}
		pthread_mutex_unlock (&mutex_led);
	}

	return 0;
}