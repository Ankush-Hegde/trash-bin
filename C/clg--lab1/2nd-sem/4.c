#include<stdio.h>
main()
{
intnum,rev=0,rem,n;
printf("\nEnter a number");
scanf("%d",&num);
n=num;
while(num!=0)
{
rem=num%10;
rev=rev*10+rem;
num=num/10;
}
printf("\nReversed number is%d", rev);
if(rev==n)
{
printf("\nGiven number is Palindrome");
}
else
{
printf("\nGiven number is not Palindrome ");
}
}
