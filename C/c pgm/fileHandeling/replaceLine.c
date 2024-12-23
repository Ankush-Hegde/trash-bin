// C program to replace the specified line
// in an existing text file

#include <stdio.h>
#include <string.h>

int main()
{
    FILE* fp1;
    FILE* fp2;

    char ch;

    int line = 0;
    int temp = 1;
    int flag = 0;

    char newText[32] = "\nMy New Line";

    fp1 = fopen("includehelp.txt", "r");
    if (fp1 == NULL) {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1)) {
        ch = getc(fp1);
        printf("%c", ch);
    }
    rewind(fp1);

    printf("\nEnter line number to replace the line: ");
    scanf("%d", &line);
    fflush(stdout);

    fp2 = fopen("temp.txt", "w");

    while (!feof(fp1)) {
        ch = getc(fp1);

        if (ch == '\n')
            temp++;

        if (temp != line) {
            putc(ch, fp2);
        }
        if (flag == 0 && temp == line) {
            fwrite(newText, 1, strlen(newText), fp2);

            flag = 1;
        }
    }

    fclose(fp1);

    fclose(fp2);

    remove("includehelp.txt");

    rename("temp.txt", "includehelp.txt");

    printf("\nModified file:\n");

    fp1 = fopen("includehelp.txt", "r");
    if (fp1 == NULL) {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1)) {
        ch = getc(fp1);
        printf("%c", ch);
    }

    fclose(fp1);

    printf("\n");

    return 0;
}

