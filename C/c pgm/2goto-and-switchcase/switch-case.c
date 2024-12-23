//checks for oval using switch case
#include <stdio.h>
int main()
{
char ch;
printf("enter the character : ");
scanf("%c",&ch);
switch (ch)
{
case 'A':
case 'a':
	 printf("%c is ovwel\n",ch);
	break;
case 'E':
case 'e':
	printf("%c is ovwel\n",ch);
	break;
case 'I':
case 'i':
	printf("%c is ovwel\n",ch);
	break;
case 'O':
case 'o':
	printf("%c is ovwel\n",ch);
	break;
case 'U':
case 'u':
	printf("%c is ovwel\n",ch);
	break;
	default : printf("%c is not ovwel\n",ch);
}
}
