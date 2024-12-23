#include<stdio.h>
void main()
{
int a[100],n,key,pos,i,mid;
int first,last,found;
printf("Enter No. of array elements\n");
scanf("%d",&n);
printf("Enter the Values\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
first=0;
last=n-1;
found=0;
printf("Enter Key value to be search\n");
scanf("%d",&key);
while(first<=last)
{
mid=(first+last)/2;
if (key==a[mid])
{
pos=mid+1;
found=1;
break;
}
else if(key<a[mid])
{last=mid-1;
}
else
{
first=mid+1;
}
}
if(found==1)
{
printf("key found at the %d position\n",pos);
}
else
{
printf("Key is found\n");
}
}
