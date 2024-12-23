//print reminder and quotient of devident and devisor
#include<stdio.h>
float rem,quo;
int a,b;
void main()
{
	printf("enter divident\n");
	scanf("%d",&a);
	printf("enter divisor\n");
	scanf("%d",&b);
	rem=a%b;
	quo=a/b;
	printf("the reminder and quotient of %d and %d is %0.4f and %0.4f respectively\n",a,b,rem,quo);
}
