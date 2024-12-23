#include <stdio.h>
void main()
{
int a,b,c;
printf("enter three numbera,b,c\n");
scanf("%d%d%d",&a,&b,&c);
if (a>b)
	{
	if (a>c)
	{
	printf("a is a larger :%d\n",a);
	}
else
	{
	printf("c is larger:%d\n",c);
	}
}
else
	{
	if (b>c)
	
	printf("b is larger:%d\n",b);
	
	else{ printf("c is larger\n");}
	}
}
