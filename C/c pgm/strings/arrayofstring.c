//C program to create and print array of strings
#include <stdio.h>

#define MAX_STRINGS	10
#define STRING_LENGTH	50

int main()
{
	//declaration
	char strings[MAX_STRINGS][STRING_LENGTH];
	int loop,n;
	
	printf("Enter total number of strings: ");
	scanf("%d",&n);
	
	printf("Enter strings...\n");
	for(loop=0; loop<n; loop++)
	{
		printf("String [%d] ? ",loop+1);
		
		getchar(); //read & ignore extra character (NULL)
		//read string with spaces
		scanf("%[^\n]s",strings[loop]);
	}
	
	printf("\nStrings are...\n");
	for(loop=0; loop<n; loop++)
	{
		printf("[%2d]: %s\n",loop+1,strings[loop]);
	}
		
	return 0;
}

