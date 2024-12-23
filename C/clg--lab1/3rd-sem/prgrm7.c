#include<stdio.h>
#include<stdlib.h>
struct node
{
 char usn[10];
 char name[20];
 char branch[10];
 int sem;
 long int pno;
 struct node *next;
};
typedef struct node *NODE;
NODE start=NULL;
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();
NODE read();

int main()
{
 int choice,n,i,flag=0;
 do
  {
   printf("\n.........SINGLY LINKED LIST MENU......\n");
   printf("1.CREATE\n2.DISPLAY\n3.INSERT AT END\n4.DELETE FROM END\n5.INSERT AT FRONT\n6.DELETE FROM FRONT\n7.EXIT\n");
   printf("enter your choice\n");
   scanf("%d",&choice);
  switch(choice)
   {
   case 1:if(flag==0)
    {
     printf("enter the number of students:\n");
     scanf("%d",&n);
     for(i=1;i<n;i++)
      {
       printf("student %d details\n",i);
       insert_front();
      }
   flag=1;
  }
else
{
  printf("students details already exits\n");
}
break;
   case 2:display();
 break;
   case 3:insert_end();
break;
   case 4:delete_end();
break;
   case 5:insert_front();
break;
   case 6:delete_front();
break;
   case 7:exit(0);
default:printf("invalid choice\n");
 }
}while(choice!=7);
 return 0;
}


NODE read()
 {
  NODE t;
  t=(NODE)malloc(sizeof(struct node));
  printf("enter USN:");
  scanf("%s",t->usn);
  printf("enter name:");
  scanf("%s",t->name);
  printf("enter branch\n");
  scanf("%s",t->branch);
  printf("enter semester");
  scanf("%d",&t->sem);
  printf("enter the phone number");
  scanf("%ld",&t->pno);
return(t);
}


void insert_front()
 {
 NODE temp;
 temp=read();
 if(start==NULL)
  {
   temp->next=NULL;
   start=temp;
   }
 else
 {
  temp->next=start;
  start=temp;
 }
}


void insert_end()
 {
  NODE q,temp;
  temp=read();
  temp->next=NULL;
 if(start==NULL)
  {
   start=temp;
  }
else
{
 q=start;
 while(q->next!=NULL)
  q=q->next;
  q->next=temp;
  }
}


void delete_front()
{
 NODE q;
 if(start==NULL)
  {
   printf("the list is empty\n");
  }
 else
 {
  q=start;
  start=start->next;
  printf("deleted student USN is %s\n\n",q->usn);
  free(q);
 }
}


void delete_end()
 {
  NODE q,t;
  if(start==NULL)
   {
    printf("the list is empty\n");
   }
 else if(start->next==NULL)
  {
   printf("delete student USN is %s\n\n",start->usn);
   start=NULL;
   free(start);
  }
 else
{
 q=start;
 while(q->next!=NULL)
  q=q->next;
  t=q->next;
  q->next=NULL;
  printf("deleted student USN is %s\n\n",t->usn);
  free(t);
 }
}
 

void display()
{
 int count=0;
 NODE q;
 if(start==NULL)
  {
   printf("list is emoty\n");
  }
 else
 {
  q=start;
  printf("the students details are:\n");
  printf("USN\tname\tbranch\tsemester\tphone number\n");
  printf("............................\n");
  while(q!=NULL)
  {
  printf("%s\t%s\t%s\t%d\t%ld\n",q->usn,q->name,q->branch,q->sem,q->pno);
  q=q->next;
  count++;
  }
}
printf("\ntotal number of students details in the list are:%d\n",count);
}


