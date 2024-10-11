#ifndef __CAN_ANAYSE_H__
#define __CAN_ANAYSE_H__
#include "stdint.h"
#define CAN_BUF_SIZE    200
#define CAN_DATA_BUF_NUM    10
#define DATA_ID_EMPTY   0XFFFFFFFF

#define CAN_DATA_PACKET_TX_HEAD     0x5A
#define CAN_DATA_PACKET_RX_HEAD     0xA5
#define CAN_DATA_PACKET_MIN_SIZE    7

//功能码
#define	EVENT_CODE_DEVICE			    0x00			//设备功能码
#define	EVENT_CODE_LOCK				      0x01			//锁功能码
#define	EVENT_CODE_LED_DISP		     0x02      //LED显示屏功能码
#define	EVENT_CODE_LCD				        0x03      //LCD16032功能码
#define	EVENT_CODE_TFT_LCD		      0x04      //TFT屏功能码
#define	EVENT_CODE_WEIGHT			  0x05      //称功能码
#define	EVENT_CODE_IR_SENSOR	  0x06      //IR传感器功能码
#define	EVENT_CODE_MEDI_BOX		   0x07      //药盒功能码
#define EVENT_CODE_LAYER			     0X10			//层控功能码

//命令码
//1.设备功能类命令码
#define DEVICE_CMD_CHECK                0x00         //上报设备信息
#define DEVICE_CMD_SETID                  0x01         //设置ID 
//2.锁功能类命令码

//3.LED显示屏类命令码

//4.LCD显示屏类命令码

//5.称类命令码

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