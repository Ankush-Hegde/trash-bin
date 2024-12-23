/*C - Read Content of a File using getc() 
using C Program.*/
 
#include <stdio.h>
 
int main(){
 
    //file nane
    const char *fileName="sample.txt";
    //file pointer
    FILE *fp;
    //to store read character
    char ch;
     
    //open file in read mode
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Error in opening file.\n");
        return -1;
    }
    printf("Content of file\n");
    while((ch=getc(fp))!=EOF){
        printf("%c",ch);
    }
    fclose(fp);
     
    return 0;
}

