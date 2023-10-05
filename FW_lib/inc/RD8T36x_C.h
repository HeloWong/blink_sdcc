// 转换后的代码如下
//
////////////////////////////////////////////////////////////////
/*--------------------------------------------------------------------------
RD8T36x_C.H

C Header file for RD8T36x microcontroller.
Copyright (c) 2022 Hefei Redefine electronic Co., Ltd.
All rights reserved.
合肥市新定义电子有限公司
版本号:  V1.0
日期:  2022.04.11
Patch: SDCC
--------------------------------------------------------------------------*/

#ifndef _RD8T36x_H_
#define _RD8T36x_H_

#include <compiler.h>

///* ------------------- 字节寄存器-------------------- */
/*CPU*/
SFR(SP, 0X81);   // 堆栈指针
SFR(DPL, 0X82);  // DPTR数据指针低位
SFR(DPH, 0X83);  // DPTR数据指针高位
SFR(DPL1, 0X84); // DPTR1数据指针低位
SFR(DPH1, 0X85); // DPTR1数据指针高位
SFR(DPS, 0X86);  // DPTR选择寄存器
SFR(PSW, 0XD0);  // 程序状态字寄存器
SFR(ACC, 0XE0);  // 累加器Ａ
SFR(EXA0, 0XE9); // 扩展累加器0
SFR(EXA1, 0XEA); // 扩展累加器1
SFR(EXA2, 0XEB); // 扩展累加器2
SFR(EXA3, 0XEC); // 扩展累加器3
SFR(EXBL, 0XED); // 扩展B寄存器0
SFR(EXBH, 0XEE); // 扩展B寄存器1
SFR(B, 0XF0);    // B寄存器

/*SRAM*/
SFR(EXADH, 0XF7); // 外部SRAM操作地址高位

/*system*/
SFR(PCON, 0X87); // 电源管理控制寄存器

/*Interrupt*/
SFR(IE, 0XA8);  // 中断控制寄存器
SFR(IE1, 0XA9); // 中断控制寄存器1
SFR(IE2, 0XAA); // 中断使能寄存器2
SFR(IP, 0XB8);  // 中断优先权控制寄存器
SFR(IP1, 0XB9); // 中断优先级控制寄存器1
SFR(IP2, 0XBA); // 中断优先级控制寄存器2

/*PORT*/
SFR(P0, 0X80);      // P0口数据寄存器
SFR(P1, 0X90);      // P1口数据寄存器
SFR(P1CON, 0X91);   // P1口输入/输出控制寄存器
SFR(P1PH, 0X92);    // P1口上拉电阻控制寄存器
SFR(DDRCON, 0X93);  // 显示驱动控制寄存器
SFR(P1VO, 0X94);    // P1口显示驱动输出寄存器
SFR(IOHCON0, 0X96); // IOH设置寄存器0
SFR(IOHCON1, 0X97); // IOH设置寄存器1
SFR(P0CON, 0X9A);   // P0口输入/输出控制寄存器
SFR(P0PH, 0X9B);    // P0口上拉电阻控制寄存器
SFR(P0VO, 0X9C);    // P0口显示驱动输出寄存器
SFR(P2, 0XA0);      // P2口数据寄存器
SFR(P2CON, 0XA1);   // P2口输入/输出控制寄存器
SFR(P2PH, 0XA2);    // P2口上拉电阻控制寄存器
SFR(P2VO, 0XA3);    // P2口显示驱动输出寄存器
SFR(P3, 0XB0);      // P3口数据寄存器
SFR(P3CON, 0XB1);   // P3口输入/输出控制寄存器
SFR(P3PH, 0XB2);    // P3口上拉电阻控制寄存器
SFR(P3VO, 0XB3);    // P3口显示驱动输出寄存器
SFR(P4, 0XC0);      // P4口数据寄存器
SFR(P4CON, 0XC1);   // P4口输入/输出寄存器
SFR(P4PH, 0XC2);    // P4口上拉电阻控制寄存器
SFR(P5, 0XD8);      // P5口数据寄存器
SFR(P5CON, 0XD9);   // P5口输入/输出控制寄存器
SFR(P5PH, 0XDA);    // P5口上拉电阻控制寄存器

/*模拟比较器*/
SFR(CMPCFG, 0XB6); // 模拟比较器设置寄存器
SFR(CMPCON, 0XB7); // 模拟比较器控制寄存器

/*TIMER*/
SFR(TCON, 0X88);   // 定时器控制寄存器
SFR(TMOD, 0X89);   // 定时器工作模式寄存器
SFR(TL0, 0X8A);    // 定时器0低8位
SFR(TL1, 0X8B);    // 定时器1低8位
SFR(TH0, 0X8C);    // 定时器0高8位
SFR(TH1, 0X8D);    // 定时器1高8位
SFR(TMCON, 0X8E);  // 定时器频率控制寄存器
SFR(TXCON, 0XC8);  // 定时器2/3/4控制寄存器
SFR(TXMOD, 0XC9);  // 定时器2/3/4工作模式寄存器
SFR(RCAPXL, 0XCA); // 定时器2/3/4重载/捕捉低8位
SFR(RCAPXH, 0XCB); // 定时器2/3/4重载/捕捉高8位
SFR(TLX, 0XCC);    // 定时器2/3/4低8位
SFR(THX, 0XCD);    // 定时器2/3/4高8位
SFR(TXINX, 0XCE);  // 定时器控制寄存器指针

/*ADC*/
SFR(ADCCFG0, 0XAB); // ADC设置寄存器0
SFR(ADCCFG1, 0XAC); // ADC设置寄存器1
SFR(ADCCON, 0XAD);  // ADC控制寄存器
SFR(ADCVL, 0XAE);   // ADC 结果寄存器
SFR(ADCVH, 0XAF);   // ADC 结果寄存器
SFR(ADCCFG2, 0XB5); // ADC设置寄存器2

/*PWM*/
SFR(PWMCFG, 0XD1);  // PWM设置寄存器
SFR(PWMCON0, 0XD2); // PWM0控制寄存器0
SFR(PWMCON1, 0XD3); // PWM1控制寄存器1
SFR(PWMPDL, 0XD4);  // PWM0周期寄存器低8位
SFR(PWMPDH, 0XD5);  // PWM0周期寄存器高8位
SFR(PWMDFR, 0XD6);  // PWM0死区设置寄存器
SFR(PWMFLT, 0XD7);  // PWM0故障检测设置寄存器

/*WatchDog*/
SFR(WDTCON, 0XCF); // WDT控制寄存器

/*BTM*/
SFR(BTMCON, 0XFB); // 低频定时器控制寄存器

/*INT*/
SFR(INT0F, 0XB4); // INT0 下降沿中断控制寄存器
SFR(INT0R, 0XBB); // INT0 上降沿中断控制寄存器
SFR(INT1F, 0XBC); // INT1 下降沿中断控制寄存器
SFR(INT1R, 0XBD); // INT1 上降沿中断控制寄存器
SFR(INT2F, 0XBE); // INT2 下降沿中断控制寄存器
SFR(INT2R, 0XBF); // INT2 上降沿中断控制寄存器

/*IAP */
SFR(IAPKEY, 0XF1); // IAP保护寄存器
SFR(IAPADL, 0XF2); // IAP写入地址低位寄存器
SFR(IAPADH, 0XF3); // IAP写入地址高位寄存器
SFR(IAPADE, 0XF4); // IAP扩展地址寄存器
SFR(IAPDAT, 0XF5); // IAP数据寄存器
SFR(IAPCTL, 0XF6); // IAP控制寄存器

/*uart0*/
SFR(OTCON, 0X8F); // 输出控制寄存器
SFR(SCON, 0X98);  // 串口控制寄存器
SFR(SBUF, 0X99);  // 串口数据缓存寄存器

/*三合一*/
SFR(US0CON0, 0X95); // USCI0控制寄存器0
SFR(US0CON1, 0X9D); // USCI0控制寄存器1
SFR(US0CON2, 0X9E); // USCI0控制寄存器2
SFR(US0CON3, 0X9F); // USCI0控制寄存器3
SFR(US1CON0, 0XA4); // USCI1控制寄存器0
SFR(US1CON1, 0XA5); // USCI1控制寄存器1
SFR(US1CON2, 0XA6); // USCI1控制寄存器2
SFR(US1CON3, 0XA7); // USCI1控制寄存器3
SFR(USXCON0, 0XC4); // USCI2/3/4/5控制寄存器0
SFR(USXCON1, 0XC5); // USCI2/3/4/5控制寄存器1
SFR(USXCON2, 0XC6); // USCI2/3/4/5控制寄存器2
SFR(USXCON3, 0XC7); // USCI2/3/4/5控制寄存器3
SFR(USXINX, 0XDC);  // USCI2/3/4/5控制寄存器指针

/*OPTION*/
SFR(OPINX, 0XFE); // Option指针
SFR(OPREG, 0XFF); // Option寄存器

/*CRC*/
SFR(OPERCON, 0XEF); // 运算控制寄存器
SFR(CRCINX, 0XFC);  // CRC指针
SFR(CRCREG, 0XFD);  // CRC寄存器

///* ------------------- 位寄存器-------------------- */
/*PSW*/
SBIT(CY, 0XD0 /*PSW*/,
     7); // 标志位          0:加法运算最高位无进位，或者减法运算最高位无借位时
         // 1:加法运算最高位有进位，或者减法运算最高位有借位时
SBIT(AC, 0XD0 /*PSW*/,
     6); // 进位辅助标志位  0:无借位、进位
         // 1:加法运算时在bit3位有进位，或减法运算在bit3位有借位时
SBIT(F0, 0XD0 /*PSW*/, 5);  // 用户标志位
SBIT(RS1, 0XD0 /*PSW*/, 4); // 工作寄存器组选择位
SBIT(RS0, 0XD0 /*PSW*/, 3); // 工作寄存器组选择位
SBIT(OV, 0XD0 /*PSW*/, 2);  // 溢出标志位
SBIT(F1, 0XD0 /*PSW*/, 1);  // F1标志
SBIT(P, 0XD0 /*PSW*/, 0); // 奇偶标志位      0:ACC中1的个数为偶数（包括0个）
                          // 1:ACC中1的个数为奇数

/*TXCON*/
SBIT(TFX, 0XC8 /*TXCON*/, 7); // 定时器2/3/4溢出标志位
SBIT(EXFX, 0XC8 /*TXCON*/,
     6); // TnEX(n=2/3/4)引脚外部事件输入(下降沿)被检测到的标志位
SBIT(RCLKX, 0XC8 /*TXCON*/,
     5); // UART0接收时钟控制位        0: 定时器1产生接收波特率	1:
         // 定时器2产生接收波特率
SBIT(TCLKX, 0XC8 /*TXCON*/,
     4); // UART0发送时钟控制位        0: 定时器1产生发送波特率	1:
         // 定时器2产生发送波特率
SBIT(
    EXENX, 0XC8 /*TXCON*/,
    3); // TnEX(n=2/3/4)引脚上的外部事件输入(下降沿)用作重载/捕获触发器允许/禁止控制
SBIT(TRX, 0XC8 /*TXCON*/,
     2); // 定时器2/3/4开始/停止控制位 0: 停止定时器2             1: 开始定时器2
SBIT(TX, 0XC8 /*TXCON*/, 1); // 定时器2/3/4定时器/计数器方式选定位
SBIT(CP, 0XC8 /*TXCON*/, 0); // 捕获/重载方式选定位

/*IP*/
SBIT(IPADC, 0XB8 /*IP*/,
     6); // ADC中断优先权选择         0:设定 ADC的中断优先权是 “低”      1:设定
         // ADC的中断优先权是 “高”
SBIT(IPT2, 0XB8 /*IP*/,
     5); // Timer2中断优先权选择      0:设定 Timer 2的中断优先权是 “低” 1:设定
         // Timer 2的中断优先权是 “高”
SBIT(IPUART, 0XB8 /*IP*/,
     4); // UART中断优先权选择        0:设定 UART的中断优先权是 “低”     1:设定
         // UART的中断优先权是 “高”
SBIT(IPT1, 0XB8 /*IP*/,
     3); // Timer1中断优先权选择      0:设定 Timer 1的中断优先权是 “低” 1:设定
         // Timer 1的中断优先权是 “高”
SBIT(IPINT1, 0XB8 /*IP*/,
     2); // INT1计数器中断优先权选择  0:设定 INT1的中断优先权是 “低”     1:设定
         // INT1的中断优先权是 “高”
SBIT(IPT0, 0XB8 /*IP*/,
     1); // Timer0中断优先权选择      0:设定 Timer 0的中断优先权是 “低” 1:设定
         // Timer 0的中断优先权是 “高”
SBIT(IPINT0, 0XB8 /*IP*/,
     0); // INT0计数器中断优先权选择  0:设定 INT0的中断优先权为 “低”     1:
         // INT0中断优先权为高

/*IE*/
SBIT(EA, 0XA8 /*IE*/,
     7); // 中断使能的总控制       0:关闭所有的中断      1:打开所有的中断
SBIT(EADC, 0XA8 /*IE*/,
     6); // ADC中断使能控制        0:关闭ADC中断         1:打开ADC中断
SBIT(ET2, 0XA8 /*IE*/,
     5); // Timer2中断使能控制     0:关闭TIMER2中断      1:打开TIMER2中断
SBIT(EUART, 0XA8 /*IE*/,
     4); // UART中断使能控制       0:关闭SIF中断         1:打开SIF中断
SBIT(ET1, 0XA8 /*IE*/,
     3); // Timer1中断使能控制     0:关闭TIMER1中断      1:打开TIMER1中断
SBIT(EINT1, 0XA8 /*IE*/,
     2); // 外部中断1中断使能控制  0:关闭外部中断1中断   1:打开外部中断1中断
SBIT(ET0, 0XA8 /*IE*/,
     1); // Timer0中断使能控制     0:关闭TIMER0中断      1:打开TIMER0中断
SBIT(EINT0, 0XA8 /*IE*/,
     0); // 外部中断0中断使能控制  0:关闭外部中断0中断   1:打开外部中断0中断

/*TCON*/
SBIT(
    TF1, 0X88 /*TCON*/,
    7); // T1溢出中断请求标志位
        // T1产生溢出，发生中断时，硬件将TF1置为“1”，申请中断，CPU响应时，硬件清“0”。
SBIT(
    TR1, 0X88 /*TCON*/,
    6); // 定时器T1的运行控制位	0:Timer1禁止计数		1:Timer1开始计数
SBIT(
    TF0, 0X88 /*TCON*/,
    5); // T0溢出中断请求标志位
        // T0产生溢出，发生中断时，硬件将TF0置为“1”，申请中断，CPU响应时，硬件清“0”。
SBIT(
    TR0, 0X88 /*TCON*/,
    4); // 定时器T0的运行控制位	0:Timer0禁止计数		1:Timer0开始计数

/*SCON*/
SBIT(SM0, 0X98 /*SCON*/,
     7); // 串行通信模式控制位:与SM1配合使用 00: 模式0，8位半双工同步通信模式
         // 01: 模式1，10位全双工异步通信 11: 模式3，11位全双工异步通信
SBIT(SM1, 0X98 /*SCON*/, 6); // 串行通信模式控制位
SBIT(SM2, 0X98 /*SCON*/,
     5); // 串行通信模式控制位2，此控制位只对模式3有效
         // 0：每收到一个完整数据帧就置位RI产生中断请求
         // 1：收到一个完整的数据帧时，只有当RB8=1时才会置位RI产生中断请求
SBIT(REN, 0X98 /*SCON*/, 4); // 接收允许控制位  0:不允许接受数据 1：允许接受数据
SBIT(TB8, 0X98 /*SCON*/, 3); // 只对模式3有效，为发送数据的第9位
SBIT(RB8, 0X98 /*SCON*/, 2); // 只对模式3有效，为接收数据的第9位
SBIT(TI, 0X98 /*SCON*/, 1);  // 发送中断标志位
SBIT(RI, 0X98 /*SCON*/, 0);  // 接收中断标志位

/******************* P0 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：P00/P01/P02/P03
 *RD8T36X20封装未引出的管脚：P00/P01/P02/P03
 ***************************************************/
SBIT(P07, 0X80 /*P0*/, 7);
SBIT(P06, 0X80 /*P0*/, 6);
SBIT(P05, 0X80 /*P0*/, 5);
SBIT(P04, 0X80 /*P0*/, 4);
SBIT(P03, 0X80 /*P0*/, 3);
SBIT(P02, 0X80 /*P0*/, 2);
SBIT(P01, 0X80 /*P0*/, 1);
SBIT(P00, 0X80 /*P0*/, 0);

/******************* P1 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：P14/P15/P16/P17
 *RD8T36X20封装未引出的管脚：P10/P12/P14/P15/P16/P17
 ***************************************************/
SBIT(P17, 0X90 /*P1*/, 7);
SBIT(P16, 0X90 /*P1*/, 6);
SBIT(P15, 0X90 /*P1*/, 5);
SBIT(P14, 0X90 /*P1*/, 4);
SBIT(P13, 0X90 /*P1*/, 3);
SBIT(P12, 0X90 /*P1*/, 2);
SBIT(P11, 0X90 /*P1*/, 1);
SBIT(P10, 0X90 /*P1*/, 0);

/******************* P2 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：无
 *RD8T36X20封装未引出的管脚：P24/P25/P26/P27
 ***************************************************/
SBIT(P27, 0XA0 /*P2*/, 7);
SBIT(P26, 0XA0 /*P2*/, 6);
SBIT(P25, 0XA0 /*P2*/, 5);
SBIT(P24, 0XA0 /*P2*/, 4);
SBIT(P23, 0XA0 /*P2*/, 3);
SBIT(P22, 0XA0 /*P2*/, 2);
SBIT(P21, 0XA0 /*P2*/, 1);
SBIT(P20, 0XA0 /*P2*/, 0);

/******************* P3 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：P34/P35/P36/P37
 *RD8T36X20封装未引出的管脚：P34/P35/P36/P37
 ***************************************************/
SBIT(P37, 0XB0 /*P3*/, 7);
SBIT(P36, 0XB0 /*P3*/, 6);
SBIT(P35, 0XB0 /*P3*/, 5);
SBIT(P34, 0XB0 /*P3*/, 4);
SBIT(P33, 0XB0 /*P3*/, 3);
SBIT(P32, 0XB0 /*P3*/, 2);
SBIT(P31, 0XB0 /*P3*/, 1);
SBIT(P30, 0XB0 /*P3*/, 0);

/******************* P4 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：P46/P47
 *RD8T36X20封装未引出的管脚：P44/P45/P46/P47
 ***************************************************/
SBIT(P47, 0XC0 /*P4*/, 7);
SBIT(P46, 0XC0 /*P4*/, 6);
SBIT(P45, 0XC0 /*P4*/, 5);
SBIT(P44, 0XC0 /*P4*/, 4);
SBIT(P43, 0XC0 /*P4*/, 3);
SBIT(P42, 0XC0 /*P4*/, 2);
SBIT(P41, 0XC0 /*P4*/, 1);
SBIT(P40, 0XC0 /*P4*/, 0);

/******************* P5 ***************************
 *RD8T36P48封装未引出的管脚：无
 *RD8T36P32封装未引出的管脚：P54/P55
 *RD8T36X20封装未引出的管脚：P5
 ***************************************************/
SBIT(P55, 0XD8 /*P5*/, 5);
SBIT(P54, 0XD8 /*P5*/, 4);
SBIT(P53, 0XD8 /*P5*/, 3);
SBIT(P52, 0XD8 /*P5*/, 2);
SBIT(P51, 0XD8 /*P5*/, 1);
SBIT(P50, 0XD8 /*P5*/, 0);

/****************************************************************************
 *注意：封装未引出的管脚，需设置为强推挽输出模式
 *IC选型：请根据所使用的IC型号,在初始化完IO口后，调用相对应的未引出管脚的IO口配置;
 *如若选RD8T36P48，则不用调用宏定义。
 *****************************************************************************/
#define RD8T36P32_NIO_Init()                                                   \
  {                                                                            \
    P0CON |= 0x0F, P1CON |= 0xF0, P3CON |= 0xF0, P4CON |= 0xC0, P5CON |= 0xF0; \
  } // RD8T36P32的未引出来的IO口配置
#define RD8T36X20_NIO_Init()                                                   \
  {                                                                            \
    P0CON |= 0x0F, P1CON |= 0xF0, P2CON |= 0XF0, P3CON |= 0xF0, P4CON |= 0xF0, \
        P5CON |= 0xFF;                                                         \
  } // RD8T36X20的未引出来的IO口配置
#endif