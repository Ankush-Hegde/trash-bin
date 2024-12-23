import java.util.Scanner;
public class ExceptionDemo
{
    public static void main(String[] args)
    {
        int a,b;
        int res;
        Scanner in= new Scanner(System.in);
        System.out.println("Enter the numbers a and b");
        a=in.nextInt();
        b=in.nextInt();
        try
        {
            res=a/b;
            System.out.println("Result of division is "+res);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Exception "+e);
        }
    }
}