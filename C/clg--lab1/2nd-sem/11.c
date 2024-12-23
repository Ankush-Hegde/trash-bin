#include<stdio.h>
main()
{
int n,a[20],i,temp,j;
printf("Enter the number of elements:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Array before sorting:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
for(i=0;i<=n-1;i++)
{
for(j=0;j<=n-1-i;j++)
{
if(a[j]<a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}printf("Elements after sorting:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
