#include<stdio.h>
void strconcatinate(char str1[20],char str2[20]);
void strcompare(char str1[20],char str2[20]);
void strlength(char str1[20]);
void main()
{
char str1[20],str2[20];
printf("Enter th first string\n");
scanf("%s",str1);
printf("Enter th second string\n");
scanf("%s",str2);
strconcatinate(str1,str2);
strcompare(str1,str2);
strlength(str1);
strlength(str2);
}
void strconcatinate(char str1[20],char str2[20])
{
char finalstr[30];
int i,j;
for(i=0;str1[i]!='\0';i++)
finalstr[i]=str1[i];
finalstr[i]=' ';
for(j=0;str2[j]!='\0';j++)
finalstr[i+j+1]=str2[j];
finalstr[i+j+1]='\0';
printf("After concatination: %s\n",finalstr);}
void strcompare(char str1[20],char str2[20])
{
char finalstr[30];
int i=0;
while(str1[i]==str2[i]&&str1[i]!='\0'&&str2[i]!='\0')
i=i+1;
if(str1[i]=='\0'&&str2[i]=='\0')
printf("Strings are equal\n");
else
printf("Strings are not equal\n");
}
void strlength(char str1[20])
{
int i;
for(i=0;str1[i]!='\0';i++);
printf("Length of the string is %d\n"
