//prints ascii value from A to Z
#include<stdio.h>
void main()
{
	int count1,count2;
	count1='A';
start0://using goto function
	printf("the ascii value of %c is %d\n",count1,count1);
	count1++;
	if(count1<='Z')
		goto start0;
	count2='a';
start2:
	printf("the ascii value of %c is %d\n",count2,count2);
	count2++;
	if(count2<='z')
		goto start2;
}
