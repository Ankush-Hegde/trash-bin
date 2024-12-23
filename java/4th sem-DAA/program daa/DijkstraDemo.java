import java.util.*;
public class DijkstraDemo
{
    static int dist []=new int[20];
    static int visited []=new int[20];
    static int path []=new int[20];
    static int source;
    public static void main(String [] args)
    {
        int u,v,n;
        int w[][]=new int[20][20];
        int i,j;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the no of nodes");
        n=in.nextInt();
        System.out.println("Enter the weight matrix");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                w[i][j]=in.nextInt();
            }
        }
        System.out.println("Enter the source vertex");
        source=in.nextInt();
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
        }
        visited[source]=1;
        for(i=1;i<=n;i++)
        {
            dist[i]=w[source][i];
        }
        for(i=1;i<=n;i++)
        {
            path[i]=source;
        }
        path[source]=-1;
        for(i=1;i<n;i++)
        {
            u=minDistance(n);
            visited[u]=1;
            v=1;
            while(v<=n)
            {
                if((dist[u]+w[u][v]<dist[v]) && visited[v]==0)
                {
                    dist[v]=dist[u]+w[u][v];
                    path[v]=u;
                }
                v++;
            }
        }
        printShortest(n);
    }
    public static int minDistance(int n)
    {
        int i,minDist,minIndex=0;
        minDist=999;
        for(i=1;i<=n;i++)
        {
            if(dist[i]<minDist && visited[i]==0)
            {
                minDist=dist[i];
                minIndex=i;
            }
        }
        return minIndex;
    }
    public static void printShortest(int n)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(i!=source)
            {
                System.out.println("The shortest distance from node "+source+" to"+i+" ="+dist[i]);
                System.out.print("The shortest path from node "+source+" to"+i+" is:");
                System.out.print(source);
                printPath(path,i);
                System.out.println();
            }
        }
    }
    public static void printPath(int path[],int j)
    {
        if(path[j]==-1)
        return;
        printPath(path,path[j]);
        System.out.print("--->"+j+"");
    }
}