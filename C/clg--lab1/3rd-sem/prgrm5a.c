#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
double compute(char symbol,double op1, double op2)
{
switch(symbol)
{
case '+':return op1 + op2;
case '-':return op1 - op2;
case '*':return op1 * op2;
case '/':if(op2==0)
  {
  printf("divide by zero error\n");
  exit(0);
  }
 else
  {
  return op1/op2;
  }
case '$':
case '^':return pow(op1,op2);
case '%':return (int)op1%(int)op2;
default:return 0;
}
}
void main()
{
 double s[20],res,op1,op2;
 char postfix[20],symbol;
 int top=-1,i;
 printf("\nenter the postfix expression:\n");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
symbol=postfix[i];
if(isdigit(symbol))
s[++top]=symbol-'0';
else
{
op2=s[top--];
op1=s[top--];
res=compute(symbol,op1,op2);
s[++top]=res;
}
}
res=s[top--];
printf("\nthe results is:%f\n",res);
}
