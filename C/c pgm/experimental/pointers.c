#include <stdio.h>
void main()
{
int x,y;
int *p;

x=10;
p=&x;
y=*p;

printf("value of x is %d\n",x);
printf("x is stored at adress = %u\n",&x);
printf("x is stored at adress = %p\n",&x);
printf("value of x using pointer = %d\n",*p);
printf("adress of x using pointer = %u\n",p);
printf("value of x in y = %d\n",y);

*p=25;

printf("now  x is changed from 10 to %d using pointer\n",x);


}
