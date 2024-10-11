#include "can_anayse.h"
#include "can.h"
#include "crc.h"

static Can_Tpe s_can;

static void Split_Date(void);
static void Device_CMDProess(uint32_t id,uint8_t *dat);
static void Can_DataCheck(Struct_CanDataBuf *buf);
void can_handler(void)
{
    uint8_t i;
    Split_Date();//分割数据
    for(i=0;i<CAN_DATA_BUF_NUM;i++)
    {
        Can_DataCheck(&s_can.rxBuf[i]);
    }
}

static void Split_Date(void)
{
    uint8_t i;
    struct can_frame frame;
    while(can0_rx(&frame)>=0)//存在数据
    {
       for(i=0; i<CAN_DATA_BUF_NUM; i++)
       {
            if(frame.can_id == s_can.rxBuf[i].addr)
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
                    s_can.rxBuf[i].addr = frame.can_id;
                    memcpy(&s_can.rxBuf[i].dat[s_can.rxBuf[i].len],frame.data,frame.can_dlc);
                    s_can.rxBuf[i].len += frame.can_dlc;
                    break;
                }
             }
       }
    }
}   

static void Can_DataCheck(Struct_CanDataBuf *buf)
{
    uint16_t crc;
    if(buf->addr != DATA_ID_EMPTY)//说明这一轮有数据
    {
        if(buf->dat[0] == CAN_DATA_PACKET_RX_HEAD)
        {
            if(buf->len >= CAN_DATA_PACKET_MIN_SIZE)
            {
                crc = CRC16_Calculate(&buf->dat[0],buf->dat[1]-2);
                if(crc == buf->dat[buf->dat[1]-2] <<8 | buf->dat[buf->dat[1]-1] )
                {
                    printf("校验成功，进入函数判断");
                    switch(buf->dat[2])
                    {
                        case EVENT_CODE_DEVICE:
                           Device_CMDProess(buf->addr,&buf->dat[3]);
                        break;
                    }
                }
            }
            else
            {
                buf->addr = DATA_ID_EMPTY;
                buf->len = 0;
            }
        }
    }
}

static void Device_CMDProess(uint32_t id,uint8_t *dat)
{
    
    switch(dat[0])
    {
        case   DEVICE_CMD_CHECK:
             printf("ID<0x%08x>:类型:%d,版本:%d",id,dat[1],(dat[2]<<8 | dat[3]));
        break;
    }
}