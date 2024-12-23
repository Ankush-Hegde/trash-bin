// C program to check a specified file exist or not 
// using stat() function

#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
	struct stat buff;
    	int isFileExist = 0;
    
    	isFileExist = stat("includehelp.txt",&buff);
    
    	if(isFileExist == 0)
	{
		printf("file exists.\n");
		return 1;
    	}
	
	printf("file does not exists.\n");
    
    	return 0;
}

