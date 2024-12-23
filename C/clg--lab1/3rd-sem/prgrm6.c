#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
char cq[MAXSIZE],item;
int front=0,rear=-1,count=0;
void cqinsert();
void cqdelete();
void cqdisplay();
void main()
{
int ch;
do
{
 printf("\n......CIRCULAR QUEUE MENU.....\n");
printf("\n1.INSERT INTO CIRCULAR QUEUE\n2.DELETE FROM CIRCULAR QUEUE\n3.DISPLAY CIRCULAR QUEUE\n4.EXIT\n");
printf("\n\nENTER YOUR CHOICE");
scanf("%d",&ch);
switch(ch)
{
 case 1:cqinsert();
       break;
 case 2:cqdelete();
       break;
 case 3:cqdisplay();
       break;
 case 4:exit(0);
       break;
default:printf("\ninvalid choice\n");
 }
}
while(ch!=4);
}
void cqinsert()
{
if(count==MAXSIZE)
{
 printf("\nCIRCULAR QUEUE OVERFLOW");
 return;
}
else
{
 printf("\nenter the item to be inserted:\t");
__fpurge(stdin);
scanf("%c",&item);
rear=(rear+1)%MAXSIZE;
cq[rear]=item;
count++;
printf("\n rear=%d front=%d\n",rear,front);
 }
}
void cqdelete()
{
 if(count==0)
  {
  printf("\nCIRCULAR QUEUE IS UNDERFLOW");
  return;
}
else
{
item=cq[front];
printf("\nDELETED ELEMENT FROM QUEUE IS %c\n",item);
front=(front+1)%MAXSIZE;
count--;
printf("\nrear=%d front=%d\n",rear,front);
 }
}
void cqdisplay()
{
 int i;
 if(count==0)
{
 printf("CIRCULAR QUEUE IS EMPTY\n");
 return;
}
else
{
 printf("the circular queue elements are\n");
for(i=front;i!=rear;i=(i+1)%MAXSIZE)
{
 printf("%c\t",cq[i]);
 }
 printf("%c\n",cq[i]);
 }
}
