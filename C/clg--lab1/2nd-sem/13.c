#include<stdio_ext.h>
struct student
{
int usn;
char name[20];
float marks;
}st[20];
void main()
{
int n,i;
float avgmarks,totmarks=0.0;
printf("Enter the number of student\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the details of student:%d\n",i+1);
printf("\nEnter USN:\n");
scanf("%d",&st[i].usn);
printf("\n Enter the name:\n");
scanf("%s",st[i].name);
printf("\nEnter the marks:\n");
scanf("%f",&st[i].marks);
}
printf("Students details are:\n----------------------\n");
printf("\n usn\t name\t marks\t\n");
printf("------------------------");
for(i=0;i<n;i++){
printf("\n\n%d\t%s\t%0.2f\n",st[i].usn,st[i].name,st[i].marks);
}
for(i=0;i<n;i++)
{
totmarks=totmarks+st[i].marks;
}
avgmarks=totmarks/n;
printf("\nAverage mark is %0.2f\n",avgmarks);
int m=0,l=0;
for(i=0;i<n;i++)
{
if(st[i].marks>=avgmarks)
{
m++;
}
else{
l++;
}
}
printf("\n %dStudents are having marks more than avgmarks\n%d Students are having marks less
than avgmarks\n",m,l);
}
