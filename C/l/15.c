#include <stdio.h>
#include <string.h>
void main()
{
char a [12];//={'h','e','l','l','o'};
char b [17];//={'o','o','o','o','o','o'};
int i;
printf("enter the string a\n");
gets(a);
printf("enter a string b\n");
gets(b);

for (i=0;a[i]!='\0';i++)
{
a[i]=b[i];
}
a[i]='\0';
puts(a);
puts(b);
}
