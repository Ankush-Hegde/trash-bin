//this program is to get exact minimum bit required to store int in binary
#include<stdio.h>
int countbit(int n)
{
	int count=0,i;
	if(n==0)
		return 0;
	for(i=0;i<32;i++)
	{
		if((1<<i)&n)//"leftshift" and "bitwise-and" operator is used
			count=i;
	}
	return ++count;
}
void main()
{
	int n;
	printf("enter the integer:\n");
	scanf("%d",&n);
	printf("the minimum bit required for %d in binary is %d",n,countbit(n));
}
