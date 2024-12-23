// C program to check a specified file has read, write,
// and execute permission or not

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int ret = 0;

    ret = access("includehelp.txt", R_OK);
    if (ret != -1)
        printf("includehelp.txt has read access");
    else
        printf("includehelp.txt has not read access");

    ret = access("includehelp.txt", W_OK);
    if (ret != -1)
        printf("\nincludehelp.txt has write access");
    else
        printf("\nincludehelp.txt has not write access");

    ret = access("includehelp.txt", X_OK);
    if (ret != -1)
        printf("\nincludehelp.txt has execute access");
    else
        printf("\nincludehelp.txt has not execute access");

    printf("\n");

    return 0;
}

