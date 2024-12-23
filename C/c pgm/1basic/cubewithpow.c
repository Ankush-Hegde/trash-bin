//cube of a number using pow() function
#include<stdio.h>
#include<math.h>
float a;
void main()
{
	printf("enter the number\n");
	scanf("%f",&a);
	//cube=pow(a,3);
	printf("the cube of %0.4f is %0.4f\n",a,pow(a,3));
}
