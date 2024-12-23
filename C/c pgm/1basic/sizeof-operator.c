//using size of operator to get size of int function char function...etc
#include<stdio.h>
void main()
{
	char a='A';
	int b=12;
	float c=23.8;
	double d=13.01;
	char str[10]="hello";

	printf("size of char %c is %d\n",a,sizeof(a));
	printf("size of int %d is %d\n",b,sizeof(b));
	printf("size of float %f is %d\n",c,sizeof(c));
	printf("size of double %f is %d\n",d,sizeof(d));
	printf("size of string %s is %d\n",str,sizeof(str));
}
