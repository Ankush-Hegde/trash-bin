//C program to create a text file using file handling, example of fopen, fclose

#include< stdio.h >
int main()
{
 
    FILE *fp;   /* file pointer*/
    char fName[20];
 
    printf("Enter file name to create :");
    scanf("%s",fName);
 
    /*creating (open) a file, in “w”: write mode*/
    fp=fopen(fName,"w");
    /*check file created or not*/
    if(fp==NULL)
    {
        printf("File does not created!!!");
        exit(0); /*exit from program*/
    }
 
    printf("File created successfully.");
    return 0;
}

