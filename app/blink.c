#include <rd8_gpio.h>
#include <rd8_uart0.h>

typedef enum 
{
	LED_DI = 0,
	LED_EN = 1
}LED_STEAE_ENUM;

#define LED1 P23
#define LED2 P22
#define LED3 P31
#define LED4 P32
#define LED5 P33
#define LED6 P37
#define LED7 P40
#define LED8 P41
#define LED9 P46
#define LED10 P51
#define LED11 P50
#define LED12 P06
#define LED13 P05
#define LED14 P03
#define LED15 P02
#define LED16 P01
#define LED17 P24
#define LED18 P25
#define LED19 P26
#define LED20 P00

void led_init(void) {
    GPIO_Init(GPIO0, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO5, GPIO_PIN_0|GPIO_PIN_1,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO4, GPIO_PIN_6|GPIO_PIN_1|GPIO_PIN_0,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO3, GPIO_PIN_7|GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO2, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,GPIO_MODE_OUT_PP);
	GPIO_Init(GPIO0, GPIO_PIN_0|GPIO_PIN_1,GPIO_MODE_OUT_PP);
	
	GPIO_WriteHigh(GPIO0, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6);
	GPIO_WriteHigh(GPIO5, GPIO_PIN_0|GPIO_PIN_1);
	GPIO_WriteHigh(GPIO4, GPIO_PIN_6|GPIO_PIN_1|GPIO_PIN_0);
	GPIO_WriteHigh(GPIO3, GPIO_PIN_7|GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);
	GPIO_WriteHigh(GPIO2, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6);
	GPIO_WriteHigh(GPIO0, GPIO_PIN_0|GPIO_PIN_1);
}

void LED_ShowSet(unsigned char LED, LED_STEAE_ENUM State)
{
	switch(LED)
	{
		case 1:
			LED1 = !State;
			break;
		case 2:
			LED2 = !State;
			break;
		case 3:
			LED3 = !State;
			break;
		case 4:
			LED4 = !State;
			break;
		case 5:
			LED5 = !State;
			break;
		case 6:
			LED6 = !State;
			break;
		case 7:
			LED7 = !State;
			break;
		case 8:
			LED8 = !State;
			break;
		case 9:
			LED9 = !State;
			break;
		case 10:
			LED10 = !State;
			break;
		case 11:
			LED11 = !State;
			break;
		case 12:
			LED12 = !State;
			break;
		case 13:
			LED13 = !State;
			break;
		case 14:
			LED14 = !State;
			break;
		case 15:
			LED15 = !State;
			break;
		case 16:
			LED16 = !State;
			break;
		case 17:
			LED17 = !State;
			break;
		case 18:
			LED18 = !State;
			break;
		case 19:
			LED19 = !State;
			break;
		case 20:
			LED20 = !State;
			break;
		
	}
}

__bit UartSendFlag = 0; //发送中断标志位
__bit UartReceiveFlag = 0; //接收中断标志位
UART0_HandleInfoDef UART0_HandleInfo;

void Uart_Int(void)
{
  if(UART0_GetFlagStatus(UART0_FLAG_TI))
  {
    UART0_ClearFlag(UART0_FLAG_TI);
    if(UART0_Transmit_IRQHandler(&UART0_HandleInfo) == Status_OK)
      UartSendFlag = 1;
  }
  if(UART0_GetFlagStatus(UART0_FLAG_RI))
  {
    UART0_ClearFlag(UART0_FLAG_RI);
    if(UART0_Receive_IRQHandler(&UART0_HandleInfo) == Status_OK)
      UartReceiveFlag = 1;
  }
}

void Uart_Test(void)
{
  while(1)
  {
    uint8_t RxData[10] = {0};
		
    UART0_HandleInfo.TxState = UART0_HandleInfo.RxState = UART0_STATE_READY;
		//接收10Byte的数据
    if(UART0_Receive_IT(&UART0_HandleInfo, RxData, 10) == Status_OK)
    {
      while(!UartReceiveFlag);
      UartReceiveFlag = 0;
			//发送接收到的数据
      if(UART0_Transmit_IT(&UART0_HandleInfo, RxData, 10) == Status_OK)
      {
        while(!UartSendFlag);
        UartSendFlag = 0;
      }
    }
  }
}

void main(void) {
    led_init();
    Uart_Int();
    
    int i=0;
    Uart_Test(); 
    // while(1) {
    //     for (i=1; i<=20; i++) {
    //         LED_ShowSet(i, LED_EN);
    //     }
    // }
}