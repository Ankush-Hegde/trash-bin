//this converts decimal to binary
#include<stdio.h>
void binary();
void no()
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
int z;
void main()
{
printf("enter 1 to continue and 0 for exit\n");
scanf("%d",&z);
switch (z)
  {
   case 1 : no();
   break;
   case 0 :
   break;
   	default : printf("enter 0 or 1\n"); main();
  }
}
