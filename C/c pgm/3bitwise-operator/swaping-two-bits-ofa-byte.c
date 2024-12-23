#include<stdio.h>
void main()
{
	int n;
	printf("enter the number in decimal:\n");
	scanf("%d",&n);
	
	int bit_1 = (n>>1)&1;//get 1st bit from number

	int bit_2 = (n>>2)&1;//get 2nd bit from number

	int xor_of_bit = bit_1 ^ bit_2; //get xor of bit1 and bit2
	printf("after swapping the bits,data value is :%d\n",n^(xor_of_bit << 1 |xor_of_bit <<2));
}
