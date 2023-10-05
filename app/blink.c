#include <rd8_gpio.h>

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

void main(void) {
    led_init();
    int i=0; 
    while(1) {
        for (i=1; i<=20; i++) {
            LED_ShowSet(i, LED_EN);
        }
    }
}