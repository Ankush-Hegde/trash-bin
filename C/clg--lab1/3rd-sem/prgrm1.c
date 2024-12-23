#include<stdio.h>
#include<stdlib.h>
#define amsize 6
int a[amsize],n,i,pos,elem;

void create();
void display();
void insert();
void delete();

int main()
{
int ch;
do
{
printf("\n........MENU.........\n");
printf("1.CREATE\n");
printf("2.DISPLAY\n");
printf("3.INSERT\n");
printf("4.DELETE\n");
printf("5.EXIT\n");
printf("\nENTER YOUR CHOICE:\t");
scanf("%d",&ch);
switch(ch)
{
  case 1:create();
  break;
  case 2:display();
  break;
  case 3:insert();
  break;
  case 4:delete();
  break;
  case 5:exit(0);
  break;
  default:printf("\ninvalid choice\n");
  break;
}
}
while(ch!=5);
return 0;
}
void create()
{
printf("\nenter the size of the array element:\t");
scanf("%d",&n);
printf("\nenter the element for the array:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
}
void display()
{
printf("\nthe array element are\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}

void insert()
{
printf("\nenter the position for new element:\t");
scanf("%d",&pos);
if((n==amsize)||(pos>n))
{
printf("\nenter an array is full or given position is invalid");
return;
}
else
{
printf("\nenter the new element to be inserted");
scanf("%d",&elem);
for(i=n-1;i>=pos;i--)
{
a[i+1]=a[i];
}
a[pos]=elem;
n=n+1;
display();
}
}
void delete()
{
printf("\nenter the position of the element to be deleted:");
scanf("%d",&pos);
if((n==0)||(pos>=n))
{
printf("\neither an array is empty or given position is invalid");
return;
}
else
{
elem=a[pos];
for(i=pos;i<n-1;i++)
{
a[i]=a[i+1];
}
printf("\nthe deleted element is %d",elem);
n=n-1;
display();
}
}






