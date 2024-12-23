import java.util.Scanner;
public class HamiltonCycleDemo
{
    static int n;
    static int graph[][];
    static int x[];
    static int flag=0,hamcnt=0,hcount=0;
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter no.of vertices");
        n=in.nextInt();
        graph=new int[n+1][n+1];
        x=new int[n+1];
        System.out.println("Enter adjacency matrix of graph");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                graph[i][j]=in.nextInt();
            }
        }
        for(int i=1;i<=n;i++)
        {
            x[i]=0;
        }
        x[1]=1;
        hamiltonian(2);
        if(flag==0)
            System.out.println("The given graph G doesnot have any hamiltonian cycles");
        System.out.println("\n******************************************\n");
    }
    public static void hamiltonian(int k)
    {
        while(true)
        {
            nextValue(k);
            if(x[k]==0)
            {
                return;
            }
            if(k==n)
            {
                flag=1;
                hamcnt++;
                System.out.println("\nHamoltonian Cycle"+hamcnt+"is");
                for(int i=1;i<=n;i++)
                {
                    System.out.print(""+x[i]+"-");
                }
                System.out.print("1"+"\n");
            }
            else
                hamiltonian(k+1);
        }
    }
    public static void nextValue(int k)
    {
        int j;
        while(true)
        {
            x[k]=(x[k]+1)%(n+1);
            if(x[k]==0)
                return;
            if(graph[x[k-1]][x[k]]!=0)
            {
                for(j=1;j<=k-1;j++)
                {
                    if(x[j]==x[k])
                        break;
                }
                if(j==k)
                {
                    if((k<n)||((k==n)&&(graph[x[n]][x[1]]==1)))
                        return;
                }
            }
        }
    }
}