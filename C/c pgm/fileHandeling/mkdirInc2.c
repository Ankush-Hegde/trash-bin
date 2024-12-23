// C program to create a directory
// using system() function

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dirName[16];
    char cmd[32] = { 0 };

    int ret = 0;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    sprintf(cmd, "mkdir %s", dirName);

    ret = system(cmd);

    if (ret == 0)
        printf("Directory created successfully\n");
    else
        printf("Unable to create directory %s\n", dirName);

    return 0;
}

