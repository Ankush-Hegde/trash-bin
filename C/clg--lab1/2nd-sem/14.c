#include<stdio.h>
#include<math.h>
void main()
{
float a[10],*ptr,mean,std,sum=0,sumstd=0;
int n,i;
printf("enter the number of elements:\n");
scanf("%d",&n);
printf("enter the array elements\n");
for(i=0;i<n;i++)
{
scanf("%f",&a[i]);
}
ptr=a;
for(i=0;i<n;i++)
{
sum=sum+*ptr;
ptr++;
}
mean=sum/n;
ptr=a;
for(i=0;i<n;i++)
{
sumstd=sumstd+pow((*ptr-mean),2);
ptr++;
}
std=sqrt(sumstd/n);printf("sum=%f\n",sum);
printf("mean=%f\n",mean);
printf("standard deviation=%f\n",std);
}
