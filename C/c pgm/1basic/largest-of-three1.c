//largest of three number using loop
#include<stdio.h>
float a,b,c,largest;
void main()
{
	printf("enter the three number\n");
	scanf("%f%f%f",&a,&b,&c);
	if(a>b && a>c)
		largest=a;
	else if(b>a && b>c)
		largest=b;
	else
		largest=c;
	printf("the largest number is %0.2f",largest);
}
