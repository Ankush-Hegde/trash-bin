#include<stdio.h>
#include<stdlib.h>
#include"date.h"

int main()
{
	int d,m,y;
	struct date d1;
		d1.d=10;
		d1.m=8;
		d1.y=2021;
		printf("the date is %d/%d/%d\n",d1.d,d1.m,d1.y);
		next_day(&d1);
		printf("\n the date is %d/%d/%d\n",d1.d,d1.m,d1.y);
		return 0;
}
