//subtract two number
#include<stdio.h>
float a,b,c;
void main()
{
	printf("ENTER THE FIRST NUMBER \n");
	scanf("%f",&a);
	printf("ENTER THE SECOND NUMBER\n");
	scanf("%f",&b);
	c=a-b;
	printf("the subtraction of %0.4f and %0.4f is %0.2f\n",a,b,c);
}
