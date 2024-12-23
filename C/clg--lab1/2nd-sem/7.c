#include<stdio.h>
void main()
{
int num,count;
printf("Enter a number\n");
scanf("%d",&num);
count=prime(num);
if(count>2)
printf("%d is not aprime no.\n",num);
else
printf("%d is a prime no.\n",num);
}
int prime(num)
{
int count=0;
int i;
for(i=1;i<=num;i++)
{
if(num%i==0)
{
count++;
}
}
return count;
}
