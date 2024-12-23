import java.util.Scanner;
import java.util.StringTokenizer;
class Customer
{
    String name;
    String dateOfBirth;
    String str;
    Scanner in = new Scanner(System.in);
    void readNameDate()
    {
        System.out.println("Enter the name of the customer");
        name=in.nextLine();
        System.out.println("Enter the DOB of the customer in dd/mm/yyyy format");
        dateOfBirth=in.nextLine();
        str="<"+name+","+dateOfBirth+">";
        System.out.println("DOB of the customer in the input format is :"+str);
    }
    void displayNameDate()
    {
        StringTokenizer st=new StringTokenizer(str);
        System.out.print("DOB of the customer in required format is:");
        System.out.print(st.nextToken("/")+",");
        System.out.print(st.nextToken("/")+",");
        System.out.println(st.nextToken());
    }
}
public class CustomerDate
{
    public static void main(String[] args)
    {
        Customer c=new Customer();
        c.readNameDate();
        c.displayNameDate();
    }
}