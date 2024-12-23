#include<stdio.h>
#include<string.h>
void main()
{
char name[20];
float unit,amt,charge;
printf("Enter the name of the custmer");
fgets(name,20,stdin);
printf("Enter the total unit");
scanf("%f", &unit);
if(unit<=200)
{
amt=0.80*unit;
}
else if(unit<=300)
{
amt=160+0.90*(unit-200);
}
else
{
amt=250+1*(unit-300);
}
amt=amt+100;
if(amt>400)
{
charge=amt*0.15;
}
else
{
charge=0;
}
amt=amt+charge;
printf("Custmer name is %s and electric bill is %0.2f", name, amt);
}
