#include "can_anayse.h"
#include "can.h"

void can_handler(void)
{
    struct can_frame frame;
        if(can0_rx(&frame)>=0)
        {
            print_can_frame(&frame);//输出can数据帧信息
        }
}