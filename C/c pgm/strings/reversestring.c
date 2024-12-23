//C program to reverse a string using recursion
// C program to reverse a string using recursion

#include <string.h>
#include <stdio.h>

void StrRev(char str[], int i, int len)
{
    char t;
    int j;

    j = len - i;

    t = str[i];
    str[i] = str[j];
    str[j] = t;

    if (i == len / 2)
        return;

    StrRev(str, i + 1, len);
}

int main()
{
    char str[20];
    int len = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    len = strlen(str);
    StrRev(str, 0, len - 1);

    printf("Reversed string is: %s\n", str);

    return 0;
}

