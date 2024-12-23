// C program to check whether a specified file exist
// or not using access() function

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int isFileExist = 0;

    isFileExist = access("includehelp.txt", F_OK);

    if (isFileExist != -1) {
        printf("file exists.\n");
        return 1;
    }

    printf("file does not exists.\n");
    return 0;
}

