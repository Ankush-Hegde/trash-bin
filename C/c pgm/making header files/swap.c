#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)//since ur sending adress to acesss u need to use pointer
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
int main()
{
	int a,b;
	printf("enter first number \n");
	scanf("%d",&a);
	printf("enter second number\n");
	scanf("%d",&b);
	swap(&a,&b);//u cant swap number just by sending variable as a=2 and b=3 u need to send the adress of variable
	printf("the first number is %d and second number is %d respectively\n",a,b);
return 0;
}
/*void swap(int a,int b)
{
	a+=b;
	b=a-b;
	a-=b;
}*/
