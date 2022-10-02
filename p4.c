#include<lpc214x.h>
unsigned int x=0;
__irq void timer0_ISR(void)
{
    x ^=1;
	if(x)
	    IOSET1=1<<20;
	else
	    IOCLR1=1<<20;
    T0IR=0x1;
	VICVectAddr=0X00000000;
}
int main()
{
	IODIR1=1<<20;
	T0MCR=0x03;
	T0MR0=0X1000;
	VICVectAddr4=(unsigned) timer0_ISR;
	VICVectCntl4=0X00000024;
	VICIntEnable=0X10;
	T0TCR=0X1;
	for(;;){};
}