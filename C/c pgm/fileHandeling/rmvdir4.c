// C program to remove empty directory
// using rmdir() function

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char dirName[16];
    int ret = 0;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    ret = rmdir(dirName);

    if (ret == 0)
        printf("Given empty directory removed successfully\n");
    else
        printf("Unable to remove directory %s\n", dirName);

    return 0;
}

