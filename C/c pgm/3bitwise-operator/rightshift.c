#include<stdio.h>
void main()
{
	int i,num;
	printf("enter a number :\n");
	scanf("%d",&i);
	num=(i>>2);//here right shift is i/(2^2)
	/*
	 *for example m>>4 is
	 * m/2^4 
	 */
	printf("after the rightshift(n>>2) the value is :%d\n",num);
}
