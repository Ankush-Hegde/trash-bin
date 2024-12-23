//finds cube of a number without using pow() function
#include<stdio.h>
float a,b;
void main()
{
	printf("enter the number\n");
	scanf("%f",&a);
	b=a*a*a;
	printf("the cube of %0.4f is %0.4f\n",a,b);
}
