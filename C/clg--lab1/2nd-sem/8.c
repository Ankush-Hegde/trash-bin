#include<stdio.h>
void main()
{
int a[10][10],b[10][10],i,j,p,q,m,n,c[10][10],k;
printf("Enter the no of rows and columns of matrix a\n");
scanf("%d%d",&m,&n);
printf("Enter the no of rows and columns in matrix b\n");
scanf("%d%d",&p,&q);
printf("Enter the element of matrix a\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("Enter the elements of matrix b\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
scanf("%d",&b[i][j]);
}
}
printf("First matrix a\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("Second matrix b\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n");
}
if(n==p)
{
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
c[i][j]=0;
for(k=0;k<m;k++)
{
c[i][j]=c[i][j]+(a[i][k]*b[j][k]);
}
}
}
printf("Resultant matrix is \n");
for(i=0;i<m;i++){
for(j=0;j<q;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
else

printf("multiplication not possible\n");
}

