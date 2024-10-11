#ifndef __CAN_H__
#define __CAN_H__

#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <signal.h>
#include <net/ethernet.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#define     debug_print     printf
#define CAN_FRAME_BUFFER_SIZE   1024 /*定义can缓存区大小*/
#define    CANBITRATE   250000  /*设置CAN0波特速率250k*/
/*定义缓冲区结构体*/
typedef struct CAN_BUFFER
{
    struct can_frame frame_buf[CAN_FRAME_BUFFER_SIZE];
    unsigned int out;
    unsigned int in;
}can_buf_struct;

extern volatile can_buf_struct  can0_rx_buf;
extern volatile can_buf_struct  can0_tx_buf;

/*can0 发送函数 填充数据到发送缓冲区*/
int can0_tx(struct can_frame *frame);
/*can0 接受函数 从接受缓冲区到can一帧数据*/
int can0_rx(struct can_frame *frame);
/*打印can_frame 帧数据内容*/
void print_can_frame(struct can_frame *frame);
int can_rx_tx_init(void);
#endif /*__CAN_H__ */