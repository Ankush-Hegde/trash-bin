// C program to check a specified file exist or not

#include <stdio.h>

int main(void)
{
    FILE* filePtr;

    filePtr = fopen("includehelp.txt", "r");

    if (filePtr == NULL) {
        printf("file does not exists.\n");
        return 1;
    }

    printf("file exists.\n");
    fclose(filePtr);

    return 0;
}

