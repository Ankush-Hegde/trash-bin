#include <stdio.h>
int main ()
{
int x=4;
int *ptr;
ptr=&x;
//use %u to get positive value instade of %d
printf("value of x is %d\n",x);
printf("ptr value(memory value) of x is %u\n",ptr);
printf("adress of x is %u\n",&x);
printf("adress of ptr(memory value) is %u\n",&ptr);
printf("data inside pointer is %u\n",*ptr);
printf("pointer of adress of is x %d\n",*(&x));
}
