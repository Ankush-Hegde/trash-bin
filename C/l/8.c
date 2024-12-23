
#include<stdio.h>
void main ()
{
//int opt;
float marks;
//x:
printf("enter a marks\n");
scanf("%f",&marks);
if (marks>=90)
{
printf("----------------------------\nResult:FCD\n--------------------------\n");
}
else if (marks >=60)
{
printf("----------------------------\nResult:FC\n---------------------------\n");
}
else if (marks >=40 )
{
printf("----------------------------\nResult:pass\n--------------------------\n");
}
/*else if(marks>=40)
{
printf("Result:pass\n");
}
*/
else
{
printf("-----------------------------\nResult:fail\n-------------------------\n");
}
/*printf("to enter one more mark press 1 \n ");
scanf("%d",&opt);
if (opt==1)
{
goto x;
}*/
}

