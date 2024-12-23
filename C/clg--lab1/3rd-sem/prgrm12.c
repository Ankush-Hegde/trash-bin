#include<stdio.h>
#include<stdlib.h>
#define max 10
void store(int key,int hk);
void display();
int HT[max];
int main()
{
int key,hk,ch,i;
for(i=0;i<max;i++)
  HT[i]=-1;
do
 {
 printf("\n1.insert key\n2.display hash table\n3.exit\n");
 printf("enter your choice:");
 scanf("%d",&ch);
 switch(ch)
  {
  case 1:printf("enter key:");
         scanf("%d",&key);
         hk=key%max;
         store(key,hk);
         break;
  case 2:display();
         break;
  case 3:exit(0);
         break;
  default:printf("invalid choice\n");
   }
  }
 while(ch!=3);
 return 0;
}

void store(int key,int hk)
 {
  int i,pos=-1,flag=0;
   if(HT[hk]==-1)
    {
     HT[hk]=key;
     return;
    }
 
for(i=hk+1;i<max;i++)
 {
  if(HT[hk]==-1)
   {
    pos=i;
    flag=1;
    break;
   }
 }

 if(flag==0)
  {
  for(i=0;i<hk;i++)
   {
    if(HT[i]==-1)
     {
      pos=i;
      flag=1;
      break;
      }
     }
    }
 
 if(flag==0)
  printf("hash table overflow\n");
  else
   HT[pos]=key;
  }

void display()
 {
  int i;
  printf("\nhash table:\n");
  for(i=0;i<max;i++)
  printf("%d|%d|\n",i,HT[i]);
 }
