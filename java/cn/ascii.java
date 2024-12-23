import java.util.Scanner;
public class ascii{
    public static void main(String [] args){
        char q;int m;
        while(true){
            System.out.println("enter the character");
            Scanner in = new Scanner(System.in);
            q = in.next().charAt(0);
            System.out.println(q);
        }
    }
}
