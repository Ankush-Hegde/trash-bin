//this converts decimal to binary
#include<stdio.h>
void binary();
void main ()
{
	int n;
	printf("enter a number: ");
	scanf("%d",&n);
	printf("binary value is : ");
	binary(n);
}
void binary(int b)
{
	int loop;
	for (loop=15;loop>=0;loop--)
	{
		if((1<<loop)&b)
			printf("1");
		else
			printf("0");
	}
}
