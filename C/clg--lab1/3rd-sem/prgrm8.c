#include<stdio.h>
#include<stdlib.h>
struct node
{
 char ssn[20];
 char name[20];
 char dept[20];
 char desig[20];
 int sal;
 long int phno;
 struct node *next;
 struct node *prev;
};
typedef struct node *NODE;
NODE start=NULL;
void insert_front();
void insert_end();
void delete_end();
void delete_front();
void display();
NODE read();

int main()
{
 int choice,n,i,flag=0;
 do
 {
  printf(".......DOUBLY LINKED LIST MENU......\n");
  printf("1.CREATE DLL\n 2.DISPLAY DLL\n");
  printf(".DOUBLE ENDED QUEUE DEMONSTRATION\n");
  printf("3.INSERT AT END OF DLL\n4.DELETE FROM END OF DLL\n5.INSERT AT FRONT OF DLL\n6.DELETE FROM FRONT OF DLL\n7.EXIT\n");
  printf("enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
   {
    case 1:if(flag==0)
     {
      printf("enter the number of employess\n");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
      printf("employee %d details\n",i);
      insert_end();
   }
    flag=1;

   }
  else
    {
     printf("employee details already exits\n");
    }
    break;
    case 2: display();
    break;
    case 3: insert_end();
    break;
    case 4: delete_end();
    break;
    case 5: insert_front();
    break;
    case 6: delete_front();
    break;
    case 7: exit(0);
  default:printf("invalid choice\n");
  }
}
while(choice!=7);
return 0;
}

NODE read()
 {
  NODE t;
  t=(NODE)malloc(sizeof(struct node));
  printf("enter SSN");
  scanf("%s",t->ssn);
  printf("enter name");
  scanf("%s",t->name);
  printf("enter department");
  scanf("%s",t->dept);
  printf("enter designation");
  scanf("%s",t->desig);
  printf("enter salary");
  scanf("%d",&t->sal);
  printf("enter the phonne number");
  scanf("%ld",&t->phno);
  return(t);
 }


void insert_front()
{
 NODE temp;
 temp=read();
 if(start==NULL)
  {
   temp->next=NULL;
   temp->prev=NULL;
   start=temp;
  }
 else
 {
  temp->next=start;
  temp->prev=NULL;
  start->prev=temp;
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
  temp->prev=NULL;
  }
 else
 {
  q=start;
  while(q->next!=NULL)
  q=q->next;
  temp->prev=q;
  q->next=temp;
 }
}


void delete_front()
 {
  NODE q;
  if(start==NULL)
   {
    printf("the DLL list is empty\n");
   }
  else if(start->next==NULL)
  {
   printf("deleted employee SSN is %s\n\n",start->ssn);
   start=NULL;
   free(start);
   }
  else
 {
  q=start;
  printf("deleted employee SSN is %s\n\n",q->ssn);
  start=start->next;
  free(q);
  start->prev=NULL;
  }
}


void delete_end()
 {
  NODE q,t;
  if(start==NULL)
   {
    printf("the DLL list is empty\n");
    }
  else if(start->next==NULL)
  {
   printf("deleted employee SSN is %s\n\n",start->ssn);
   start=NULL;
   free(start);
  }
 else
  {
   q=start;
   while(q->next->next!=NULL)
   {
    q=q->next;
    }
 t=q->next;
 printf("delete employee SSN is %s\n\n",t->ssn);
 q->next=NULL;
 t->prev=NULL;
 free(t);
 }
}


void display()
 {
  int count=0;
  NODE q;
  if(start==NULL)
   {
    printf("DLL list is empty\n");
    return;
   }
  else
    q=start;
    printf("the employee details are\n");
    printf("emp SSN\temp name\tdepartment\tdesignation\tsalary\tphone no\n");
    printf("...........................\n");
    while(q!=NULL)
   {
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%ld\n",q->ssn,q->name,q->dept,q->desig,q->sal,q->phno);
    q=q->next;
    count++;
   }
 printf("\ntotal number of employee in the DLL list are %d\n",count);
  }


