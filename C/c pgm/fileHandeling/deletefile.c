// C program to delete a specified file
// using remove() function

#include <stdio.h>

int main()
{
    char fileName[] = "includehelp.txt";
    int ret = 0;

    ret = remove(fileName);

    if (ret == 0)
        printf("File deleted successfully\n");
    else
        printf("Unable to delete file %s\n", fileName);

    return 0;
}

