//C program to sort strings in alphabetical order
// C program to sort strings in the alphabetical order

#include <stdio.h>
#include <string.h>

int main()
{
    char name[5][7] = { "Virat", "Rohit", "Shikar", "Hardik", "Risabh" };
    char temp[7];

    int i = 0, j = 0;

    printf("Names before sorting: \n");
    for (i = 0; i < 5; i++)
        printf("  %s\n", name[i]);

    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(name[i], name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("Sorted names: \n");
    for (i = 0; i < 5; i++)
        printf("  %s\n", name[i]);

    return 0;
}

