// C program to print the list of files
// of a directory

#include <dirent.h>
#include <stdio.h>
int main(void)
{
    DIR* dObj;
    struct dirent* dir;

    dObj = opendir("/home/root/Desktop/");

    printf("\nList of files and sub directories: \n");
    if (dObj != NULL) {
        while ((dir = readdir(dObj)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(dObj);
    }
    return (0);
}

