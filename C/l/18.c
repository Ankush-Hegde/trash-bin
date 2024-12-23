#include <stdio.h>
int main()
{
int m=124,*pm;
pm=&m;
printf("the value of m is :%d",*pm);
*pm=325;
printf("\n the value of m after pointer initalization is %d\n",*pm);

}
