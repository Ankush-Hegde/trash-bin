#include <stdio.h>
void main()
{
int a[10],n,i;
printf("enter the value of n\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the value of a[%d]\n",i);
scanf("%d",&a[i]);
}
printf("the elements of array are\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}
