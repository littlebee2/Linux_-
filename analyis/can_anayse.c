#include "can_anayse.h"
#include "can.h"

static Can_Tpe s_can;

staitc void Split_Date(void);

void can_handler(void)
{
    struct can_frame frame;
    if(can0_rx(&frame)>=0)
        {
            print_can_frame(&frame);//输出can数据帧信息
        }
}

staitc void Split_Date(void)
{
    uint8_t i;
    struct can_frame frame;
    while(can0_rx(&frame)>=0)//存在数据
    {
       for(i=0; i<CAN_DATA_BUF_NUM; i++)
       {
            if(frame.id == s_can.rxBuf[i].addr)
            {
                if((s_can.rxBuf[i].len + frame.can_dlc) <= CAN_BUF_SIZE)
                {
                    memcpy(&s_can.rxBuf[i].dat[s_can.rxBuf[i].len],frame.data,frame.can_dlc);
                    s_can.rxBuf[i].len += frame.can_dlc;
                }
            }
       }
       if(i  >= CAN_DATA_BUF_NUM)//如成立，表示之前未收到的地址数据
       {
             for(i=0; i<CAN_DATA_BUF_NUM; i++)
             {
                if(s_can.rxBuf[i].addr == DATA_ID_EMPTY)
                {
                    s_can.rxBuf[i].addr = frame.id;
                    memcpy(&s_can.rxBuf[i].dat[s_can.rxBuf[i].len],frame.data,frame.can_dlc);
                    s_can.rxBuf[i].len += frame.can_dlc;
                    break;
                }
             }
       }
    }
}   