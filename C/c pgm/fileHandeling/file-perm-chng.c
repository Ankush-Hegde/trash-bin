// C program to change the permissions of file
// using the system() function

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char fileName[16] = "file.txt";
    char cmd[32];
    int ret = 0;

    sprintf(cmd, "chmod 666 %s", fileName);

    ret = system(cmd);
    if (ret == 0)
        printf("Permissions of file changed successfully\n");
    else
        printf("Unable to change the permissions of file\n");

    return 0;
}

