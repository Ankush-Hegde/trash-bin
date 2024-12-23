#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack[MAX],item;
int top=-1,count=0,status=0;

/*push operation*/
void push(int stack[],int item)
{
if(top==(MAX-1))
printf("\n\nstack is overflow");
else
 {
  stack[++top]=item;
  status++;
 }
}

/*pop operation*/
int pop(int stack[])
{
 int ret;
 if(top==-1)
  printf("\n\nstack is underflow");
 else
  {
  ret=stack[top--];
  status--;
  printf("\npopped element is %d",ret);
  }
 return ret;
}

void paliandrome(int stack[])
{
 int i,temp;
 temp=status;
 for(i=0;i<temp;i++)
  {
  if(stack[i]==pop(stack))
  count++;
  }
 if(temp==count)
  printf("\nstack contents are paliandrome");
else
  printf("\nstack contents are not paliandrome");
}

void display(int stack[])
{
 int i;
  printf("\n the stack contents are:");
  if(top==-1)
 printf("\nstack is empty");
 else
  {
  for(i=top;i>=0;i--)
  printf("\n.......\n|%d|",stack[i]);
  printf("\n");
  }
}

void main()
 {
  int ch;
  do
  {
  printf("\n.....MAIN MENU....\n");
  printf("\n1.PUSH in the stack");
  printf("\n2.POP from the stack");
  printf("\n3.PALIANDROME check using stack");
  printf("\n4.exit");
  printf("\nenter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
case 1:printf("\nenter a element to be pushed:");
       scanf("%d",&item);
       push(stack,item);
       display(stack);
       break;
case 2:item=pop(stack);
       display(stack);
       break;
case 3:paliandrome(stack);
       break;
case 4:exit(0);
       break;
default:printf("\nEND OF EXECUTION");
}
}while(ch!=4);
}

