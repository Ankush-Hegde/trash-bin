//generate random number
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	srand(time(0));//if time is not used then it selects only 1 random number
	printf("random number is %d ",rand());//rand() is a function in stdlib.h used to select random number
}
