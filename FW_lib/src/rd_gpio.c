// 转换后的代码如下
//
////////////////////////////////////////////////////////////////
#include <compiler.h>    // 请在本网页下载此头文件(https://csy-tvgo.github.io/Keil-C51-C-to-SDCC-C-Converter/)
//************************************************************
//  Copyright (c) 合肥市新定义电子有限公司
//	文件名称: 		rd8_gpio.c
//	作者:					新定义应用团队
//	模块功能: 		GPIO固件库函数C文件
//  最后更正日期: 2023年2月13日
// 	版本: 				V1.10009
//  说明:该文件仅适用于RD8系列芯片
//*************************************************************

#include "rd8_gpio.h"

/**************************************************
*函数名称:void GPIO_DeInit(void)
*函数功能:GPIO相关寄存器复位至缺省值
*入口参数:void
*出口参数:void
**************************************************/
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
void GPIO_DeInit(void)
{
  P0CON = P1CON = P2CON = P3CON = P4CON = P5CON = 0x00;
  P0PH = P1PH = P2PH = P3PH = P4PH = P2PH = 0x00;
  P0 = P1 = P2 = P3 = P4 = P5 = 0;
}
#endif
#if defined(RD8G05x) || defined(RD8T05x)
void GPIO_DeInit(void)
{
  P0CON = P1CON = P2CON = P5CON = 0x00;
  P0PH = P1PH = P2PH = P5PH = 0x00;
  P0 = P1 = P2 =  P5 = 0;
}
#endif
#if defined(RD8G403) || defined(RD8G40x)
void GPIO_DeInit(void)
{
  P0CON = P1CON = P2CON = 0x00;
  P0PH = P1PH = P2PH = 0x00;
  P0 = P1 = P2 = 0;
}
#endif

/**************************************************
*函数名称:void GPIO_Init(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins, GPIO_Mode_TypeDef GPIO_Mode)
*函数功能:GPIO口配置初始化
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
GPIO_Pin_TypeDef:PortPins:GPIO管脚Pxy（uint8_t作为入参，方便进行位或操作）
GPIO_Mode_TypeDef:GPIO_Mode:GPIO口模式（高阻输入、上拉输入、推挽输出）
*出口参数:void
**************************************************/
void GPIO_Init(GPIO_TypeDef GPIOx, uint8_t PortPins, GPIO_Mode_TypeDef GPIO_Mode)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P0CON &= ~PortPins;
          P0PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P0CON &= ~PortPins;
          P0PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P0CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
    case GPIO1:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P1CON &= ~PortPins;
          P1PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P1CON &= ~PortPins;
          P1PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P1CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
    case GPIO2:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P2CON &= ~PortPins;
          P2PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P2CON &= ~PortPins;
          P2PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P2CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P3CON &= ~PortPins;
          P3PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P3CON &= ~PortPins;
          P3PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P3CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
    case GPIO4:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P4CON &= ~PortPins;
          P4PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P4CON &= ~PortPins;
          P4PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P4CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
    {
      switch(GPIO_Mode)
      {
        /* 配置IO为高阻输入模式 */
        case GPIO_MODE_IN_HI:
          P5CON &= ~PortPins;
          P5PH &= ~PortPins;
          break;
        /* 配置IO为上拉输入模式 */
        case GPIO_MODE_IN_PU:
          P5CON &= ~PortPins;
          P5PH |= PortPins;
          break;
        /* 配置IO为推挽输出模式 */
        case GPIO_MODE_OUT_PP:
          P5CON |= PortPins;
          break;
        default:
          break;
      }
    }
    break;
#endif
    default:
      break;
  }
}

/**************************************************
*函数名称:void GPIO_Write(GPIO_TypeDef GPIOx, uint8_t PortVal)
*函数功能:GPIO口赋值
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
uint8_t:PortVal:GPIO口的值
*出口参数:void
**************************************************/
void GPIO_Write(GPIO_TypeDef GPIOx, uint8_t PortVal)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      P0 = PortVal;
      break;
    case GPIO1:
      P1 = PortVal;
      break;
    case GPIO2:
      P2 = PortVal;
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      P3 = PortVal;
      break;
    case GPIO4:
      P4 = PortVal;
      break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      P5 = PortVal;
      break;
#endif
    default:
      break;
  }
}

/**************************************************
*函数名称:void GPIO_WriteHigh(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins)
*函数功能:GPIO口管脚Pxy置位
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
GPIO_Pin_TypeDef:PortPins:选择GPIO口管脚Pxy（uint8_t作为入参，方便进行位或操作）
*出口参数:void
**************************************************/
void GPIO_WriteHigh(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      P0 |= PortPins;
      break;
    case GPIO1:
      P1 |= PortPins;
      break;
    case GPIO2:
      P2 |= PortPins;
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      P3 |= PortPins;
      break;
    case GPIO4:
      P4 |= PortPins;
      break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      P5 |= PortPins;
#endif
      break;
    default:
      break;
  }
}

/**************************************************
*函数名称:void GPIO_WriteLow(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins)
*函数功能:GPIO口管脚Pxy复位
*入口参数:
GPIO_TypeDef:GPIOx:选择操作的GPIO口
GPIO_Pin_TypeDef:PortPins:选择配置GPIO口管脚Pxy
*出口参数:void
**************************************************/
void GPIO_WriteLow(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      P0 &= ~PortPins;
      break;
    case GPIO1:
      P1 &= ~PortPins;
      break;
    case GPIO2:
      P2 &= ~PortPins;
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      P3 &= ~PortPins;
      break;
    case GPIO4:
      P4 &= ~PortPins;
      break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      P5 &= ~PortPins;
      break;
#endif
    default:
      break;
  }
}

/**************************************************
*函数名称:uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx)
*函数功能:读GPIO口Px的值
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
*出口参数:
uint8_t:返回Px的值
**************************************************/
uint8_t GPIO_ReadPort(GPIO_TypeDef GPIOx)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      return P0;
    case GPIO1:
      return P1;
    case GPIO2:
      return P2;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      return P3;
    case GPIO4:
      return P4;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      return P5;
#endif
    default:
      return 0;
  }
}

/**************************************************
*函数名称:BitStatus GPIO_ReadPin(GPIO_TypeDef GPIOx, uint8_t PortPins)
*函数功能:读GPIO口管脚Pxy的值
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
GPIO_Pin_TypeDef:PortPins:选择GPIO口管脚Pxy（uint8_t作为入参，方便进行位或操作）
*出口参数:
BitStatus:返回Pxy的值
**************************************************/
BitStatus GPIO_ReadPin(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
  BitStatus TempBitstatus;
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      TempBitstatus = (P0 & PortPins);
      break;
    case GPIO1:
      TempBitstatus = (P1 & PortPins);
      break;
    case GPIO2:
      TempBitstatus = (P2 & PortPins);
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      TempBitstatus = (P3 & PortPins);
      break;
    case GPIO4:
      TempBitstatus = (P4 & PortPins);
      break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      TempBitstatus = (P5 & PortPins);
      break;
#endif
    default:
      TempBitstatus = RESET;
      break;
  }

  if(TempBitstatus != RESET)
    return SET;
  else
    return RESET;
}

/**************************************************
*函数名称:BitStatus GPIO_TogglePin(GPIO_TypeDef GPIOx, uint8_t PortPins)
*函数功能:翻转GPIO口管脚Pxy的值
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
GPIO_Pin_TypeDef:PortPins:选择GPIO口管脚Pxy（uint8_t作为入参，方便进行位或操作）
*出口参数:void
**************************************************/
void GPIO_TogglePin(GPIO_TypeDef GPIOx, uint8_t PortPins)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      P0 = (P0) ^ PortPins;
      break;
    case GPIO1:
      P1 = (P1) ^ PortPins;
      break;
    case GPIO2:
      P2 = (P2) ^ PortPins;
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      P3 = (P3) ^ PortPins;
      break;
    case GPIO4:
      P4 = (P4) ^ PortPins;
      break;
#endif
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
    case GPIO5:
      P5 = (P5) ^ PortPins;
      break;
#endif
    default:
      break;
  }
}

#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x) || defined(RD8G05x) || defined(RD8T05x)
/**************************************************
*函数名称:void GPIO_IOH_Config(GPIO_TypeDef GPIOx, uint8_t PortPins,GPIO_IOH_Grade_TypeDef GPIO_IOH_Grade)
*函数功能:设置GPIO口管脚IOH输出能力
*入口参数:
GPIO_TypeDef:GPIOx:待操作的GPIO口
GPIO_Pin_TypeDef:PortPins:选择GPIO口管脚Pxy
GPIO_IOH_Grade_TypeDef:GPIO_IOH_Grade:选择IOH的输出等级
*出口参数:void
**************************************************/
void GPIO_IOH_Config(GPIO_TypeDef GPIOx, GPIO_Pin_TypeDef PortPins, GPIO_IOH_Grade_TypeDef GPIO_IOH_Grade)
{
  /* 选择需要操作的GPIO */
  switch(GPIOx)
  {
    case GPIO0:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON0 &= 0xFC;
        IOHCON0 |= GPIO_IOH_Grade;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON0 &= 0xF3;
        IOHCON0 |= GPIO_IOH_Grade << 2;
      }
      break;
    case GPIO1:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON0 &= 0xCF;
        IOHCON0 |= GPIO_IOH_Grade << 4;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON0 &= 0x3F;
        IOHCON0 |= GPIO_IOH_Grade << 6;
      }
      break;
    case GPIO2:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON1 &= 0xFC;
        IOHCON1 |= GPIO_IOH_Grade;
      }
      else if(PortPins == GPIO_PIN_HNIB)
      {
        IOHCON1 &= 0xF3;
        IOHCON1 |= GPIO_IOH_Grade << 2;
      }
      break;
#if defined(RD8G36x) || defined(RD8G37x) || defined(RD8T36x) || defined(RD8T37x)
    case GPIO3:
      if(PortPins == GPIO_PIN_LNIB)
      {
        IOHCON1 &= 0xCF;
        IOHCON1 |= GPIO_IOH_Grade << 4;
      }
      break;
#endif
    default:
      break;
  }
}
#endif

/******************* (C) COPYRIGHT 2022 RDS Microelectronics *****END OF FILE****/

