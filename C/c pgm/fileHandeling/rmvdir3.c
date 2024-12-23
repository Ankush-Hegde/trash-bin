// C program to remove a non-empty directory
// using the system() command

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dirName[16];
    char cmd[32] = { 0 };

    int ret = 0;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    sprintf(cmd, "rm -rf %s", dirName);

    ret = system(cmd);

    if (ret == 0)
        printf("Given non-empty directory deleted successfully\n");
    else
        printf("Unable to delete directory %s\n", dirName);

    return 0;
}

