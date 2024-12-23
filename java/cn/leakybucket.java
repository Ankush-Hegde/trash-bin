import java.util.Random;
import java.util.Scanner;

public class leakybucket{
    public static void main(String [] args){
        int total=0,bucketsize,oprate,flow,iter,rem_byte;
        int pkt[];
        pkt = new int[500];
        Scanner in = new Scanner(System.in);
        Random rand = new Random();
        System.out.println("enter the no of iter\n");
        iter=in.nextInt();
        System.out.println("enter the bucketsize and oprate");
        bucketsize = in.nextInt();
        oprate = in.nextInt();
        System.out.println("enter the input flow");
        flow = in.nextInt();
        for(int i=0;i<iter;i++){
            for(int j=0;j<flow;j++){
                rand.setSeed(System.nanoTime());
                pkt[j] = rand.nextInt(500);
                total += pkt[j];
                if(total<=bucketsize){
                    System.out.println("input flow : "+(j+1)+"\npkt size : "+pkt[j]+ "\naccepted. \nno of bytes in bucket is "+total);
                }
                else{
                    total = pkt[j];
                    System.out.println("input flow : "+(j+1)+"\n pktsize : "+pkt[j]+"\ndiscarded \nno of bytes in bucket is : "+total);
                }
            }
            if(oprate>total){
                rem_byte=total;
                total=0;
                System.out.println("------------------------------------------------------------------------------------------");
                System.out.println("output rate of the bucket is : " +oprate+"\n bytes sent out of the bucket is : " +rem_byte);
                System.out.println("------------------------------------------------------------------------------------------");
            }
            else{
                total=oprate;
                System.out.println("------------------------------------------------------------------------------------------");
                System.out.println("output rate of the bucket is : " +oprate+"\n bytes sent out of the bucket is : " +total);
                System.out.println("-------------------------------------------------------------------------------------------");

            }
        }

    }   
}