#include<stdio.h>
#include<math.h>
void main()
{
float i=2,sum=0,term,denomenator,numerator,x,degree;
printf("Enter the value of degree");
scanf("%f",&degree);
x=degree*(3.14/180);
numerator=x;
denomenator=1;
do
{
term=numerator/denomenator;
numerator=-numerator*x*x;
denomenator=denomenator*i*(i+1);
sum=sum+term;
i=i+2;
}
while(fabs(term)>=0.000001);
printf("\n Taylor series value of sin(%f) is %0.4f",degree,sum);
printf("\n According to library function sin(%f) is %0.4f\n",degree,sin(x));
}
