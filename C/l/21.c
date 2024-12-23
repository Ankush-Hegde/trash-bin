#include <stdio.h>
#include<string.h>
void main()
{
int n,i;
printf("enter the no of student");
scanf("      %d",&n);
struct student{
		char name[15];
		int age,rollno,marks;
		char gender;
		};
struct student s;
for (i=0;i<n;i++)
{
printf("ENTER THE DETAILS OF STUDENT\n in an order of \n name\n age\n rollno\n marks\n gender\n");
scanf(" %s%d%d%d %c",s.name,&s.age,&s.rollno,&s.marks,&s.gender);
printf("the entered details are :\n name:%s\nage:%d\nrollno:%d\nmarks:%d\ngender:%c\n",s.name,s.age,s.rollno,s.marks,s.gender);
}
}
