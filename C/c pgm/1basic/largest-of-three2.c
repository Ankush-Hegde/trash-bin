//largest of two number without using loops
#include<stdio.h>
float a,b,c,largest;
void main()
{
	printf("enter the three numbers\n");
	scanf("%f%f%f",&a,&b,&c);
	largest=((a>b && a>c)?a:(b>c && b>a)?b:c);//for example(5>6?1:0)(if 5>6 is true it prints 1 else it prints 0,here wkt 5<6 so it prints 0)
	printf("the largest number is %f \n",largest);
}
