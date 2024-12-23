// C program to print the list of file or sub directories
// of the current directory

#include <dirent.h>
#include <stdio.h>

int main(void)
{
    DIR* dObj;
    struct dirent* dir;

    dObj = opendir(".");

    printf("\nList of files and sub directories: \n");
    if (dObj != NULL) {
        while ((dir = readdir(dObj)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(dObj);
    }

    return (0);
}

