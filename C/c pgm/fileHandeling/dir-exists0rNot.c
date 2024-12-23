// C program to check a specified directory 
// exist or not

#include <dirent.h>
#include <stdio.h>

int main(void)
{
    DIR* dObj;
    dObj = opendir("./image");

    if (dObj != NULL)
        printf("Directory exists.\n");
    else
        printf("Directory does not exists.\n");

    return 0;
}

