//LED
//PORT A
//PIN 5
#define PERIPH_BASE 	 (0x40000000UL)
#define AHB1PERIPH_OFF 	 (0x00020000UL)
#define AHBIPERIPH_BASE  (PERIPH_BASE + AHB1PERIPH_OFF)

#define GPIOA_OFF  		 (0x00000000UL)
#define GPIOA_BASE 		 (AHBIPERIPH_BASE + GPIOA_OFF)

#define RCC_OFF      	 (0x00003800UL)
#define RCC_BASE 		 (AHBIPERIPH_BASE + RCC_OFF )

#define AHB1EN_ROFF 	 (0x30UL)
#define RCC_AHB1EN_R 	 (*(volatile unsigned int*)(RCC_BASE + AHB1EN_ROFF ))// Clock enable Register

#define GPIOAEN 		 (1U<<0) //To enable clock for gpio port A

//Set output mode in MODER Register
#define MODER_OFF 		 (0x00UL)
#define GPIOA_MODER		 (*(volatile unsigned int*)(GPIOA_BASE+MODER_OFF))

//To turn and off LED : Need to write in output data register

#define ODR_OFF 	(0x14UL)
#define GPIOA_ODR 	(*(volatile unsigned int*)(GPIOA_BASE+ODR_OFF))

//To set led pin 5

#define PIN5  		(1U<<5)

typedef struct
{

}GPIO_TypeDef;

int main (void)
{
	/* Enable clock : gpioa
	 * Set PA5 as out pin */
	RCC_AHB1EN_R = RCC_AHB1EN_R || GPIOAEN ;
	GPIOA_MODER  = GPIOA_MODER  || (1U << 10);
	GPIOA_MODER	&= ~ (1U<<11);
	while(1)
	{
		//Set PA5 High
		GPIOA_ODR = GPIOA_ODR ^ PIN5;
		for (int i =0 ; i<100000 ; i++){}

	}
}

