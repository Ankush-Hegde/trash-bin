//C program to demonstrate the strstr() function

#include <stdio.h>
#include <string.h>

int main()
{
    char str[32] = "India is great country";
    char* ptr;

    ptr = strstr(str, "great");
    if (ptr != NULL)
        printf("String is: '%s'\n", ptr);
    else
        printf("Word 'great' is not found\n");

    ptr = strstr(str, "power");
    if (ptr != NULL)
        printf("String is: %s\n", ptr);
    else
        printf("Word 'power' is not found\n");

    return 0;
}

