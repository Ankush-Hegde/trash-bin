/** C program to create a new string after
 * removing spaces from the string
*/

#include <stdio.h>

// function to remove white spaces from the string
void remove_spaces(char *buf , int len)
{
    int i=0,j=0;
    char temp[100]={0};
    
    for(i=0,j=0 ; i<len ; i++)
    {
        if(buf[i] == ' ' && buf[i]!=NULL)
        {
            for(j=i ; j<len ; j++)
            {
                buf[j] = buf[j+1];
            }
            len--;
        }
    }
}

// main function
int main()
{
    // declare a char buffer
    char string[100]={0};
    
    // declare some local int variables
    int i=0,len=0;
    
    printf("\nEnter your string : ");
    gets(string);
    
    // calculate the length of the string
    len = strlen(string);
    
    remove_spaces(string , len);
    
    printf("\nNew string is : %s\n",string);
    return 0;
}

