//prints even or odd using if else
#include<stdio.h>
int a,rem;
void main()
{
	printf("enter the number to check enen or odd\n");
	scanf("%d",&a);
	rem=a%2;
	if(rem==0)
	{
		printf("%d is a even number\n",a);
	}	
	else
		printf("%d is a odd number\n",a);
}
