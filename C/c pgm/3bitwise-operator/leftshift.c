//to demonstrate left shift
#include <stdio.h>
void main()
{
	int n,num;
	printf("enter the number :\n");
	scanf("%d",&n);
	printf("number before leftshift(n<<2) is  %d\n",n);
	num=(n<<2);//here leftshift is n*2^2 
	/* 
	 * for example
	 * if m<<6 then here the answer is m*2^6
	*/
	printf("number after leftshift(n<<2) is %d\n",num);
}
