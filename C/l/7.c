#include<stdio.h>
void main ()
{

float marks;
x:
printf("enter a marks\n");
scanf("%f",&marks);
if (marks>=40)
{
printf("----------------------------\nResult:pass\n--------------------------\n");
}
else
{
printf("-----------------------------\nResult:fail\n-------------------------\n");
}
goto x;
}

