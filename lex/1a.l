%{
#include<stdio.h>
#include<stdlib.h>
int v=0,id=0,op=0,flag=0;
%}
%%
[a-zA-Z0-9]+	{id++;printf("\nidentifier");ECHO;}
[\+\-\=\/\*]	{op++;printf("\noperator");ECHO;}
.|\n		{;}
%%
int main(){
printf("enter an expression\n");
yylex();
printf("no of id : %d\n no of op : %d\n",id,op);
return 0;
}
int yywrap(){
return 0;
}
