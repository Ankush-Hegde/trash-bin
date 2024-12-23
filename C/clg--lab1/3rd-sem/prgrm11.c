#include<stdio.h>
#include<stdlib.h> 
int a[50][50],visited[50],front=0,rear=-1,Q[50],n,i,v;
void creategraph()
 {
  int i,j;
  printf("enter the number of nodes:");
  scanf("%d",&n);
  printf("enter the adjency matrix");
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  scanf("%d",&a[i][j]);
  }
void bfs(int v)
 {
  int i,u;
  visited[v]=1;
  rear=rear+1;
  Q[rear]=v;
  while(front<=rear)
   {
    u=Q[front];
    front=front+1;
    for(i=1;i<=n;i++)
     {
      if(a[u][i]==1&&visited[i]==0)
       {
        visited[i]=1;
        rear=rear+1;
        Q[rear]=i;
        printf("%d\t",i);
        }
      }
     }
    }
void dfs(int v)
 {
  visited[v]=1;
  for(i=1;i<=n;i++)
   {
    if(a[v][i]==1&&visited[i]==0)
     {
      printf("%d\t",i);
      dfs(i);
     }
   }
  }

void main()
 {
 int ch;
 do
  {
   printf("\n..........MENU........\n");
   printf("1.create graph\n");
   printf("2.bfs:print all nodes reaxchable from a given starting node\n");
   printf("3.dfs:print all nodes reachable4 from a given starting node\n");
   printf("4.exit\n");
   printf("enter your choice");
   scanf("%d",&ch);
  switch(ch)
   {
    case 1:creategraph();
           break;
     case 2:for(i=1;i<n;i++)
           {
            visited[i]=0;
           }
        printf("enter the starting vertex");
        scanf("%d",&v);
        printf("nodes reachable from starting vertex %d are:",v);
        bfs(v);
         break;
     case 3:for(i=1;i<=n;i++)
         {
          visited[i]=0;
         }
        printf("\nenter the startig vertex:");
        scanf("%d",&v);
        printf("\nnodes reachable from starting vertex %d are:",v);
        dfs(v);
        break;
    case 4:exit(0);
        break;
     default: printf("\ninvalid choice");
       }
   }
   while(ch!=4);
 }
  


