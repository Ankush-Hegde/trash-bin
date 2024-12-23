// C program to rename a file
// using the system() function.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char oldName[16];
    char newName[16];
    char cmd[64];

    int ret = 0;

    printf("Enter old filename: ");
    scanf("%s", oldName);

    printf("Enter new filename: ");
    scanf("%s", newName);

    sprintf(cmd, "mv %s %s", oldName, newName);
    ret = system(cmd);

    if (ret == 0)
        printf("File renamed successfully\n");
    else
        printf("Unable to rename file\n");

    return 0;
}

