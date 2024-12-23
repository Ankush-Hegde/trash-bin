//C program to eliminate/remove all vowels from a string
#include <stdio.h>
#define MAX 100

//function prototypes

/*
This function will return o if 'ch' is vowel
else it will return 1
*/
char isVowel(char ch);

/*
This function will eliminate/remove all vowels
from a string 'buf'
*/
void eliminateVowels(char *buf);

/*main function definition*/
int main()
{
	char str[MAX]={0};
	
	//read string
	printf("Enter string: ");
	scanf("%[^\n]s",str); //to read string with spaces
	
	//print Original string
	printf("Original string: %s\n",str);
	
	//eliminate vowles
	eliminateVowels(str);
	printf("After eliminating vowels string: %s\n",str);
	
	return 0;
}

//function definitions

char isVowel(char ch)
{
	if(	ch=='A' || ch=='a' ||
		ch=='E' || ch=='e' ||
		ch=='I' || ch=='i' ||
		ch=='O' || ch=='o' ||
		ch=='U' || ch=='u')
		return 0;
	else
		return 1;
}

void eliminateVowels(char *buf)
{
	int i=0,j=0;
	
	while(buf[i]!='\0')
	{
		if(isVowel(buf[i])==0)
		{
			//shift other character to the left
			for(j=i; buf[j]!='\0'; j++)
				buf[j]=buf[j+1];			
		}
		else
		    i++;
	}
	
}

