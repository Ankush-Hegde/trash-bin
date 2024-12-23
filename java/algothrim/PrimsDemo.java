import java.util.Scanner;
public class PrimsDemo
{
    public static void main(String[]args)
    {
        int i,j,k,n,source;
        int w[][]=new int[50][50];
        int visited[]=new int[20];
        int minWt,totalCost=0,ev=0,sv=0;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the no.of vertices/nodes in the graph");
        n=in.nextInt();
        System.out.println("Enter the weight/cost matrix");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                w[i][j]=in.nextInt();
            }
        }
        System.out.println("Enter the source vertex to start");
        source=in.nextInt();
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
        }
        visited[source]=1;
        for(i=1;i<n;i++)
        {
            minWt=999;
            for(j=1;j<=n;j++)
            {
                if(visited[j]==1)
                {
                    for(k=1;k<=n;k++)
                    {
                        if(visited[k]!=1 && w[j][k]<minWt)
                        {
                            sv=j;
                            ev=k;
                            minWt=w[j][k];
                        }
                    }
                }
            }
            totalCost+=minWt;
            visited[ev]=1;
            System.out.println(sv+""+"--->"+""+ev+""+"Cost:"+""+minWt);
        }
        System.out.println("The total cost of minimum spanning tree is"+totalCost);
    }
}