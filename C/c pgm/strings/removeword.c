//C program to remove a given word from the string
// C program to remove a given word from the string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[64];
    char word[16];
    char words[6][16];

    int i = 0;
    int j = 0;
    int k = 0;
    int l1 = 0;
    int l2 = 0;

    printf("Enter string: ");
    scanf("%[^\n]s", str);

    printf("Enter word: ");
    scanf("%s", word);

    while (str[i] != 0) {
        if (str[i] == ' ') {
            words[k][j] = '\0';
            k++;
            j = 0;
        }
        else {
            words[k][j] = str[i];
            j++;
        }
        i++;
    }
    words[k][j] = '\0';

    j = 0;
    for (i = 0; i < k + 1; i++) {
        if (strcmp(words[i], word) == 0)
            words[i][j] = 0;
    }

    j = 0;
    printf("Result is:\n");
    for (i = 0; i < k + 1; i++) {
        if (words[i][j] == 0)
            continue;
        else
            printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}

