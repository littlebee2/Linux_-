#ifndef __CAN_ANAYSE_H__
#define __CAN_ANAYSE_H__

#define CAN_BUF_SIZE    200
#define CAN_DATA_BUF_NUM    10
#define DATA_ID_EMPTY   0XFFFFFFFF
typedef struct 
{
    uint32_t  addr;  /*记录当前BUF存在数据的源地址*/
    uint8_t    len;     /*记录当前BUF已存在数据长度*/
    uint8_t    dat[CAN_BUF_SIZE];   /*数据域*/ 
}Struct_CanDataBuf;


typedef struct 
{
    Struct_CanDataBuf rxBuf[CAN_DATA_BUF_NUM];
    Struct_CanDataBuf txBuf[CAN_DATA_BUF_NUM];
}Can_Tpe;

void can_handler(void);

#endif /*__CAN_ANAYSE_H__ */