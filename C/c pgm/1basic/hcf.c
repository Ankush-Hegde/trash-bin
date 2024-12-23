//find hcf of two number
#include<stdio.h>
int findhcf(int a,int b)
{
	int temp;
	if(a==0||b==0)
		return 0;
	while(b!=0)
	{
	temp=a%b;
	a=b;
	b=temp;
	}
	return a;
}
void main()
{
	int a,b,hcf;
	printf("enter two number\n");
	scanf("%d%d",&a,&b);
	hcf=findhcf(a,b);
	printf("the hcf of %d and %d is %d\n",a,b,hcf);
}
