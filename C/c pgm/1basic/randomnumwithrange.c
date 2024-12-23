//print random numbers with range
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int lower=1,upper=100,num;
	srand(time(0));
	num=(rand()%(upper-lower+1))+lower;//formula to generate number with in range
	printf("random number b/w 1-100 is : %d\n",num);
}
