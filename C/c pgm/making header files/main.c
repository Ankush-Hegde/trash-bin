#include<stdio.h>
#include<stdlib.h>

	struct date{
		int d,m,y;
	};

	void next_day(struct date *d);
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

void next_day(struct date *d){
	d->d=11;
	d->m=8;
	d->y=2021;
}
