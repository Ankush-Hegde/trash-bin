//swap two numbers without two variable
#include<stdio.h>
void main()
{
	int a,b;
	printf("enter the value of a\n");
	scanf("%d",&a);
	printf("enter the value of b\n");
	scanf("%d",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("the value of a and b after swaping is %d and %d rspectively\n",a,b);
}
