// C program to remove a specified empty directory
// using the remove() function

#include <stdio.h>

int main()
{
    char dirName[16];
    int ret = 0;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    ret = remove(dirName);
    if (ret == 0)
        printf("Specified empty directory deleted successfully\n");
    else
        printf("Unable to delete directory %s\n", dirName);

    return 0;
}

