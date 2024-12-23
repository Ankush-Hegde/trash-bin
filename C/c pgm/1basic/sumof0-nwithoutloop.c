//prints sum from 0 t0 n numbers
#include<stdio.h>
void main()
{
	int n,sum;
	printf("enter the value of n\n");
	scanf("%d",&n);
	sum=(n*(n+1))/2;
	printf("the sum of 0 to %d is %d\n",n,sum);
}
