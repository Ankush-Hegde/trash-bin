#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void infix_postfix(char infix[],char postfix[]);
int sp(char symbol);
int ip(char symbol);
void main()
{
 char infix[30],postfix[30];
 printf("\nenter the valid infix expression:");
 scanf("%s",infix);
 infix_postfix(infix,postfix);
 printf("the infix expression is:%s\n",infix);
 printf("the corresponding postfix expression is:%s\n",postfix);
}
void infix_postfix(char infix[30],char postfix[30])
{
 int top=1;
 int i,j;
 char s[30],symbol;
 j=0;
 top++;
 s[top]='#';
 for(i=0;i<strlen(infix);i++)
 {
  symbol=infix[i];
  while(sp(s[top])>ip(symbol))
  {
   postfix[j]=s[top];
   top=top-1;
   j++;
  }
 if(sp(s[top]!=ip(symbol)))
 {
  top=top+1;
  s[top]=symbol;
  }
 else
 top--;
}
while(s[top]!='#')
{
 postfix[j]=s[top];
 top=top-1;
 j++;
}
postfix[j]='\0';
}
int sp(char symbol)
{
 switch(symbol)
  {
  case '+':
  case '-':return 2;
  case '*':
  case '/':return 4;
  case '^':
  case '$':return 5;
  case '(':return 0;
  case '#':return -1;
  default:return 8;
 }
}
int ip(char symbol)
 {
  switch(symbol)
  {
   case '+':
   case '-':return 1;
   case '*':
   case '/':return 3;
   case '^':
   case '$':return 6;
   case '(':return 9;
   case ')':return 0;
   default :return 9;
 }
}
