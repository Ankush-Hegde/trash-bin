// C program to rename a file using
// the rename() function

#include <stdio.h>

int main()
{
    char oldName[16];
    char newName[16];
    int ret = 0;

    printf("Enter old filename: ");
    scanf("%s", oldName);

    printf("Enter new filename: ");
    scanf("%s", newName);

    ret = rename(oldName, newName);

    if (ret == 0)
        printf("File renamed successfully\n");
    else
        printf("Unable to rename file\n");

    return 0;
}

