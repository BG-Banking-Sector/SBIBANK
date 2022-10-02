#include<lpc214x.h>
void wait()
{
	T0TCR=0X1;
	while(T0TC!=T0MR0);
}
int main()
{
	IODIR0=0XFFFFFFFF;
	T0MR0=0X1234;
	T0MCR=0X4;
	while(1)
	{
		IOSET0=0X1;
		   wait();
		IOCLR0=0X1;
		  wait();
    }
}