import java.util.Random;
class GenerateInteger extends Thread
{
    Random r= new Random();
    public void run()
    {
        try
        {
            for(int i=0;i<10;i++)
            {
                MultiThreadDemo.randomInt[i]=r.nextInt(10);
                System.out.println("Random Integer "+i+" is : "+MultiThreadDemo.randomInt[i]);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Exception "+e);
        }
    }
}
class PrintSquare extends Thread
{
    public void run()
    {
        try
        {
            for(int i=0;i<10;i++)
            {
                System.out.println("Square of number "+MultiThreadDemo.randomInt[i]+" is : "+Math.pow(MultiThreadDemo.randomInt[i],2));
                Thread.sleep(1000);
                
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Exception "+e);
        }
    }
}
class PrintCube extends Thread
{
    public void run()
    {
        try
        {
            for(int i=0;i<10;i++)
            {
                System.out.println("Cube of "+MultiThreadDemo.randomInt[i]+" is : "+Math.pow(MultiThreadDemo.randomInt[i],3));
                Thread.sleep(1000);
                
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Exception "+e);
        }
    }
}
public class MultiThreadDemo
{
    static int randomInt[]=new int[10];
    public static void main(String[] args)
    {
        try
        {
            System.out.println("Generate Random Numbers");
            GenerateInteger thread1=new GenerateInteger();
            thread1.start();
            thread1.join();
            System.out.println("Print Squares of a number");
            PrintSquare thread2=new PrintSquare();
            thread2.start();
            thread2.join();
            System.out.println("Print Cubes of a number");
            PrintCube thread3=new PrintCube();
            thread3.start();
            thread3.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("Exception "+e);
        }
    }
}
