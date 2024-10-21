#include<LPC17xx.h>
int pulsewidth[]={0,1000,2500,5000,7500};
void delay(unsigned int rl)
{
	unsigned int r ;
	for(r=0;r<r1;r++);
	return ;
}
void pwn_init(void)
{
	LPC_PINCON->PINSEL3|=0X8000;//P1.23 AT FC2 FOR OUTPUT 
	LPC_PWM1->PCR=0X1000;//ENABLE pwn1.4
	LPC_PWM1->PR=0;
	LPC_PWM1->MR0=10000;
	LPC_PWM1->MCR=2;//STOP WHEN TC=MR0;
	LPC_PWM1->LER=0XFF;
	LPC_PWM1->TCR=0X2;//RESET COUNTER
	LPC_PWM1->TCR=0X9;/COUNTER AND PWM ENABLE
}

int main(void)
{
	int x;
	LPC_PINCON->PINSEL0=0;//P0.4 TO P0.7 COLUMANS
	LPC_GPIO->FIODIR=0XF00;//P0.8 TO P0.11 ROWS
	pwm_init();
	while(1)
	{
		LPC_GPIO->FIOSET=0X100;//O/P TO ROW 0;
		x=(LPC_GPIO0->FIOPIN)&0XF0;
		if(x==1)//col 0 
			LPC_PWN1->MR4=pulsewidth[1];
		else if (x==2)// col 1 
			LPC_PWM1->MR4=pulsewidth[2];
		else if (x==4)//col 2
			LPC_PWM1->MR4=pulsewidth[3];
		else if (x==8)//col 3
			LPC_PWM1->MR4=pulsewidth[4];
		else 
			LPC_PWM1->MR4=pulsewidth[0];
		LPC_PWN1->LER=0XFF;
		delay(10000);
	}
	
}
