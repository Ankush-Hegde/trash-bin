/*
Program to remove all alphabets from given alphanumeric string in C
Example:

    Input:
    String is: "hello123"
    Output:
    Final string is: "123"

    Input:
    String is: "Call 100"
    Output:
    Final string is: "100"

*/
/* C program to remove all the characters 
* from the alphanumeric string
*/

#include <stdio.h>
#include <string.h>

// This function removes all the chars
// used in the string passed and will leave
// only the alphanumeric characters
int RemoveChars(char *string)
{
	int length=0,i=0,j=0,k=0;

	length = strlen(string);

	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if((string[j]>='a' && string[j]<='z') || (string[j]>='A' && string[j]<='Z'))
			{
				for(k=j;k<length;k++)
				{
					string[k] = string[k+1];
				}
				length--;
			}
		}
	}
}

// main function 
int main()
{
	char string[50]={0};

	printf("\nEnter the string : ");
	gets(string);

	// pass the string to the function
	RemoveChars(string);
	printf("Final string is : %s",string);
	return 0;
}

