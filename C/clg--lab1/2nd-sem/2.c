#include<stdio.h>
#include<stdlib.h>
main()
{
float num1,num2,result;
char op;
printf(“Enter the operator(+,-,*,/)\n”);
scanf(“%c”,&op);
printf(“Please enter two numbers:\n”);
scanf(“%f%f”, &num1,&num2);
if(op==’+’)
{
result=num1+num2;
printf(“result is %0.2f\n”);
}
else if(op==’-’)
{
result=num1-num2;
printf(“result is %0.2f\n”);
}
else if(op==’*’)
{
result=num1*num2;
printf(“result is %0.2f\n”);
}
else
{
{
if(num2==0)
{
printf(“please enter non zero no. For num2:\n”);
exit(0);
}
else
result=num1/num2;
printf(“result is %0.2f\n”,result);
}
}
}
