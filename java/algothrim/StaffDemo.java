import java.util.Scanner;
class Staff
{
    int staffId;
    String name;
    long phoneNo;
    int salary;
    Scanner in = new Scanner(System.in);
    void readData()
    {
        System.out.println("Enter the name of the staff");
        name = in.nextLine();
        System.out.println("Enter the staffId");
        staffId=in.nextInt();
        System.out.println("Enter the phoneNo");
        phoneNo = in.nextLong();
        System.out.println("Enter the salary");
        salary = in.nextInt();
    }
    void displayData()
    {
        System.out.println("--------------------");
        System.out.println("StaffId : "+""+staffId);
        System.out.println("Name : "+""+name);
        System.out.println("PhoneNo : "+""+phoneNo);
        System.out.println("Salary : "+""+salary);
    }
}
class StaffTeaching extends Staff
{
    String domain;
    int publications;
    void readData()
    {
        super.readData();
        in.nextLine();
        System.out.println("Enter the domain");
        domain=in.nextLine();
        System.out.println("Enter the no of publications");
        publications=in.nextInt();
    }
    void displayData()
    {
        super.displayData();
        System.out.println("Domain : "+""+domain);
        System.out.println("No on publications :"+""+publications);
        System.out.println("----------------------------");
    }
}
class StaffTechnical extends Staff
{
    String skills;
    void readData()
    {
        super.readData();
        in.nextLine();
        System.out.println("Enter the skills");
        skills=in.nextLine();
    }
    void displayData()
    {
        super.displayData();
        System.out.println("Skills are : "+""+skills);
        System.out.println("----------------------");
    }
}
class StaffContract extends Staff
{
    int contPeriod;
    void readData()
    {
        super.readData();
        System.out.println("Enter the contract period in months");
        contPeriod=in.nextInt();
    }
    void displayData()
    {
        super.displayData();
        System.out.println("Contract Period is : "+""+contPeriod+" months");
        System.out.println("----------------------------------");
    } 
}
public class StaffDemo
{
    public static void main(String[] args)
    {
        StaffTeaching stt[]=new StaffTeaching[3];
        StaffTechnical stec[]=new StaffTechnical[3];
        StaffContract stc[]=new StaffContract[3];
        System.out.println("Read Teaching Staff Details");
        for(int i=0;i<3;i++)
        {
            stt[i]=new StaffTeaching();
            System.out.println("Enter the Teaching Staff "+(i+1)+" details");
            stt[i].readData();
        }
        System.out.println("Read Technical Staff Details");
        for(int i=0;i<3;i++)
        {
            stec[i]=new StaffTechnical();
            System.out.println("Enter the Technical Staff "+(i+1)+" details");
            stec[i].readData();
        }
        System.out.println("Read Contract Staff Details");
        for(int i=0;i<3;i++)
        {
            stc[i]=new StaffContract();
            System.out.println("Enter the Contract Staff "+(i+1)+" details");
            stc[i].readData();
        }
        for(int i=0;i<3;i++)
        {
            System.out.println("Details of Teaching Staff "+(i+1)+" is :");
            stt[i].displayData();
        }
        for(int i=0;i<3;i++)
        {
            System.out.println("Details of Technical Staff "+(i+1)+" is :");
            stec[i].displayData();
        }
        for(int i=0;i<3;i++)
        {
            System.out.println("Details of Contract Staff "+(i+1)+" is :");
            stc[i].displayData();
        }
    }
}