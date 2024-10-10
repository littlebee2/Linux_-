#ifndef __LEDAPP_H__
#define __LEDAPP_H__

typedef enum
{
	LED_CLOSE=0,		//LED灯关闭
	LED_OPEN,				//LED灯打开
	LED_FLASH,			//LED灯闪烁
	LED_SINGLE			//LED灯亮一次
}Enum_LenMode;

typedef	struct
{
	unsigned short delay;
	unsigned short space;
	Enum_LenMode mode;
}Struct_LedType;


#endif /* __LEDAPP_H__*/
