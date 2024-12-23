//C program to compare strings using strcmp() function
#include <stdio.h>
#include <string.h>

int main(){
    char str1[] = "Includehelp", str2[] = "includehelp", str3[] = "Includehelp";
    int res = 0, cmp = 0;

    // Compares string1 and string2 and return the difference
    // of first unmatched character in both of the strings
    // unless a '\0'(null) character is reached.
    res = strcmp(str1, str2);

    if (res == 0)
        printf("\n %s and %s are equal\n\n", str1, str2);
    else
        printf("\n %s and %s are not equal\n\n", str1, str2);

    // Compares string1 and string3 and return the difference
    // of first unmatched character in both of the strings
    // unless a '\0'(null) character is reached.
    cmp = strcmp(str1, str3);

    if (cmp == 0)
        printf(" %s and %s are equal\n\n", str1, str3);
    else
        printf(" %s and %s are not equal\n\n", str1, str3);

    return 0;
}

