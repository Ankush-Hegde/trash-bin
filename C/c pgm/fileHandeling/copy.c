// C program to copy N bytes of from a specific offset to another file.
#include <stdio.h>
#include <string.h>
 
int main(int argc,char *argv[])
{
    FILE *fp1;
    FILE *fp2;
     
    int count       = 0;
    int location    = 0;
    int totBytes    = 0;
     
    unsigned char data[1024];
     
    if( argc < 5 )
    {
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name source-file-name target-file-name offset N\" format.\n");
        return -1;
    }
     
    fp1 = fopen(argv[1],"r");
    if( fp1 == NULL )
    {
        printf("\n%s File can not be opened : \n",argv[1]);
        return -1;
    }
     
    fseek(fp1,0,SEEK_END);
     
    count    = ftell(fp1);
    location = atoi(argv[3]);       // offset of source file to copy
    totBytes = atoi(argv[4]);       // number of bytes to copy
     
    if( count < (location  + totBytes) )
    {
        printf("\nGiven number of bytes can not be copy, due to file size.\n");
        return -1;
    }
     
    fp2 = fopen(argv[2],"w");
    if( fp2 == NULL )
    {
        printf("\n%s File can not be opened\n",argv[2]);
        return -1;
    }
 
    fseek(fp1,location,SEEK_SET);
     
    fread(data,totBytes,1,fp1);
 
    fwrite(data,totBytes,1,fp2);
     
    data[totBytes]=0;
     
    printf("\nCopied content is : \"%s\"\n",data);
 
    fclose(fp1);
    fclose(fp2);
 
    return 0;
}

