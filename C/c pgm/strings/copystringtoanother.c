//C program to copy one string to another and count copied characters
#include <stdio.h>

//function to copy the string
int copy_string(char *target, char *source)
{
	//variable tp store length, it will also work
	//as loop counter
	int len=0;
	
	//loop to run from 0 (len=0) until NULL ('\0')
	//not found
	while(source[len] != '\0')
	{
		target[len] = source [len];
		len++;
	}
	//assign NULL to the target string
	target[len] = '\0';
	
	//return 'len'- that is number of copied characters
	return len;
}

//main code
int main()
{
	//declare and assign string1 to be copied
	char str1[]="This is a test string";
	//declare string 2 as target string
	char str2[30];
	//variable to store number of copied characters
	//that will be returned by the copy_string()
	int count;
	
	//calling the function
	count = copy_string(str2,str1);
	
	//printing values
	printf("Source string (str1): %s\n",str1);
	printf("Target string (str2): %s\n",str2);
	printf("Copied characters are: %d\n",count);
	
	return 0;	
}

