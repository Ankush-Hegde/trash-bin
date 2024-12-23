//prints sum and average of two int
#include<stdio.h>
float a,b,sum,avg;
void main()
{
	printf("enter the first number\n");
	scanf("%f",&a);
	printf("enter the second number\n");
	scanf("%f",&b);
	sum=a+b;
	avg=sum/2;
	printf("the sum of %0.4f and %0.4f is %0.4f\n",a,b,sum);
	printf("the average of %0.4f and %0.4f is %0.4f\n",a,b,avg);
}
