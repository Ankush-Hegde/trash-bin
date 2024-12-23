#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,d;
float root1,root2,real,img;
printf("\nEnter the values of a b and c:\t");
scanf("%f%f%f",&a,&b,&c);
if((a==0)&&(b==0))
{
printf("\nInvalid inputs");
}
else
{
d=(b*b)-(4*a*c);
if(d==0)
{
printf("\nRoots are real and equal:::");
root1=root2=-b/(2*a);
printf("\nRoot1=%.3f\nRoot2=%.3f",root1,root2);
}
else if(d>0)
{
printf("\nRoots are real and distinct:::");
root1=(-b+sqrt(d))/(2*a);
root2=(-b-sqrt(d))/(2*a);
printf("\nRoot1=%.3f\nRoot2=%.3f",root1,root2);
}
else
{
printf("\nRoots are real and imaginary:::");
real=-b/(2*a);
img=(sqrt(fabs(d)))/(2*a);
printf("\nRoot1=%.3f+i%.3f",real,img);
printf("\nRoot2=%.3f-i%.3f",real,img);
}
}
}
