//Program to find occurrence of a character in an input string in C
#include <stdio.h>
#define MAX	100

int main()
{
	char str[MAX]={0};
	char ch;
	int count,i;
	
	
	//input a string
	printf("Enter a string: ");
	scanf("%[^\n]s",str); //read string with spaces
	
	getchar(); // get extra character (enter/return key)
	
	//input character to check frequency
	printf("Enter a character: ");
	ch=getchar();
	
	//calculate frequency of character 
	count=0;
	for(i=0; str[i]!='\0'; i++)
	{
		if(str[i]==ch)
			count++;
	}
	
	printf("\'%c\' found %d times in \"%s\"\n",ch,count,str);
	
	return 0;	
}

