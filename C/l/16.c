#include <stdio.h>
void swap(int a,int b);
void swap(int a,int b)
{
int a,b;

a=a+b ;
b=a-b ;
a=a-b ;

}

void main ()
{
int a,b;
printf("enter value of a and b");
scanf("%d%d",&a,&b);
swap(a,b);
printf("value of a after swap is %d",a);
printf("value of b after swap is %d",b);
}
