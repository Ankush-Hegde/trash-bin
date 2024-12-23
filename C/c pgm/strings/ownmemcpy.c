//Write your own memcpy() function in C
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 50

//memcpy() Implementation, name: myMemCpy()
void myMemCpy(void* target, void* source, size_t n){
	int i;
	//declare string and type casting 
	char *t = (char*)target;
	char *s = (char*)source;
	//copying "n" bytes of source to target
	for(i=0;i<n;i++)
		t[i]=s[i];
}

int main(){
	char str1[MAX_CHAR] = "Hello Wold!";
	char str2[MAX_CHAR] = "Nothing is impossible";

	printf("Before copying...\n");
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	//copying all bytes of str2 to str1
	myMemCpy(str1, str2, strlen(str2));

	printf("After copying...\n");
	printf("str1: %s\n",str1);
	printf("str2: %s\n",str2);

	return 0;
}

