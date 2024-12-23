#include<stdio.h>
int bintodec(int n);
main()
{
int decnum,n;
printf("Enter any binary no.:\n");
scanf("%d",&n);
decnum=bintodec(n);
printf("Decimal equivalent is %d\n",decnum);
}
int bintodec(int n)
{
if (n==0)
return 0;
return (n%10+2*bintodec(n/10));
}
