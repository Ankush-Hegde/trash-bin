import java.util.Scanner;
public class KnapSackDPDemo
{
    public static void main(String [] args)
    {
        int i;
        int n;
        int W;
        int wt[]=new int[10];
        int val[]=new int[10];
        Scanner in =new Scanner(System.in);
        System.out.println("Enter the no of items");
        n=in.nextInt();
        System.out.println("Enter the weight of the matrix");
        for(i=1;i<=n;i++)
        {
            wt[i]=in.nextInt();
        }
        System.out.println("Enter the value of the items");
        for(i=1;i<=n;i++)
        {
            val[i]=in.nextInt();
        }
        System.out.println("Enter the capacity of the knapsack");
        W=in.nextInt();
        System.out.println("The minimum value in knapsack of capacity"+W+"is:"+knapsack(W,wt,val,n));
    }
    public static int knapsack(int W,int wt[],int val[],int n)
    {
        int i,j;
        int v[][]=new int[n+1][W+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=W;j++)
            {
                if(i==0|j==0)
                    v[i][j]=0;
                else if(j-wt[i]<0)
                    v[i][j]=v[i-1][j];
                else
                    v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
            }
        }
        return v[n][W];
    }
    public static int max(int a,int b)
    {
        return(a>b)?a:b;
    }
}