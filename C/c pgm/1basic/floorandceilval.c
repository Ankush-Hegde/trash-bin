//finds floor and ceil value of a fraction
#include<stdio.h>
#include<math.h>//flooring value and ceiling value are library function which is decleared in math.h
void main()
{
	float a,cval,fval;
	printf("enter the value\n");
	scanf("%f",&a);
	cval=ceil(a);
	fval=floor(a);
	printf("ceil and floor value of %0.4f is %0.4f and %0.4f respectively\n",a,cval,fval);
}
