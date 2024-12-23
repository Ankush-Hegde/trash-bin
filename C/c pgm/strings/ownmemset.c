//Write your own memset() function in C
#include <stdio.h>
#include <string.h>
#define LEN 10

//memset() function implemention
//function name: myMemSet()
void myMemSet(void* str, char ch, size_t n){
	int i;
	//type cast the str from void* to char*
	char *s = (char*) str;
	//fill "n" elements/blocks with ch
	for(i=0; i<n; i++)
		s[i]=ch;
}

int main(void) {
	char arr[LEN];
	int loop;

	printf("Array elements are (before myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	//filling all blocks with 0
	myMemSet(arr,0,LEN);
	printf("Array elements are (after myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	//filling first 3 blocks with -1
	//and second 3 blocks with -2
	//and then 3 blocks with -3
	myMemSet(arr,-1,3);
	myMemSet(arr+3,-2,3);
	myMemSet(arr+6,-3,3);
	printf("Array elements are (after myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	return 0;
}

