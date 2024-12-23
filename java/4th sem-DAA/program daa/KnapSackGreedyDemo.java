import java.util.Scanner;
public class KnapSackGreedyDemo
{
    public static void main(String[]args)
    {
        int nItems;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the number of items : ");
        nItems=in.nextInt();
        double W;
        double weight[]=new double[nItems];
        double value[]=new double[nItems];
        double ratio[]=new double[nItems];
        System.out.println("Enter the weights of the item");
        for(int i=0;i<nItems;++i)
            weight[i]=in.nextDouble();
        System.out.println("Enter the values/profits of the item");
        for(int i=0;i<nItems;++i)
            value[i]=in.nextDouble();
        for(int i=0;i<nItems;++i)
            ratio[i]=value[i]/weight[i];
        System.out.println("Enter the Capacity of the knapsack :");
        W=in.nextDouble();
        System.out.println("\n The maximum value in a knapsack of capacity "+W+" is : "+computeMaxValue(W,weight,value,ratio));
    }
    public static double computeMaxValue(double W,double weight[],double value[],double ratio[])
    {
        double cW=0;
        double cV=0;
        System.out.print("\n Items considered are :");
        while(cW<W)
        {
            int item=getNextItem(weight,value,ratio);
            if(item==-1)
            {
                break;
            }
            System.out.print((item+1)+"");
            if(cW+weight[item]<=W)
            {
                cW+=weight[item];
                cV+=value[item];
                ratio[item]=0;
            }
            else
            {
                cV+=(ratio[item]*(W-cW));
                cW+=(W=cW);
                break;
            }
        }
        return cV;
    }
    public static int getNextItem(double weight[],double value[],double ratio[])
    {
        double highest=0;
        int index=-1;
        for(int i=0;i<value.length;++i)
        {
            if(ratio[i]>highest)
            {
                highest=ratio[i];
                index=i;
            }
        }
        return index;
    }
} 