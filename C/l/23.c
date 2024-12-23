#include <stdio.h>
void dfs(int source)
{
s(++top)=1;
b(source)=1;
for (v=1;v<=n;v++)
{
if (a[source][v]==1&&b[v]==0
{
printf("\n%d->%d",source,v);dfs(v);
}
}
}
void main()
{
int ch;
printf("\n Enterthe source vertex to find the connectivity:");
scanf(%d,&source);
m=1;
dfs(source);
for(i=1;i<=n;i++)
{
if (b[i]==0)
m=0;
}
if (m==1)
printf("\ngraph is connected");
else
printf("\ngraph is not connected");
}
