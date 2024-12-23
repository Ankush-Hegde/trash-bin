//program to swap two numbers
#include<stdio.h>
void main()
{
	int i,j;
	printf("enter two numbers:\n");
	scanf("%d%d",&i,&j);
	printf("before swaping i=%d and j=%d\n",i,j);
	i=i^j;
	j=i^j;
	i=i^j;
	printf("after swaping i=%d and j=%d \n",i,j);
}
