#include<stdio.h>
#include<string.h>
void main()
{
char a[5]={'a','b','c','d','e'};
char b[7]={'f','g','h','i','\0','k'};
//int len;
int k;
//strcat(a,b);
printf("a is : %s\n",a);
printf("b is : %s\n",b);
//len=strlen(a);
//printf("length is %d\n",len);
k=strcmp(a,b);
printf("%d\n",k);
}
