#include<stdio.h>
void main()
{
int i,n;
float j;
printf("Enter the number\n");
scanf("%d",&n);
j=n;
for(i=1;i<=2*n;i++)
{
j=(j+(n/j))/2.0;
}
printf("square root of %d is%0.3f\n",n,j);
}
