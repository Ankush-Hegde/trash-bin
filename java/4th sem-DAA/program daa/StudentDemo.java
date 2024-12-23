import java.util.Scanner;
class Student
{
    String usn;
    String name;
    String branch;
    long phoneNo;
    Student(String sname,String susn,String sbranch,long sphoneNo)
    {
        usn=susn;
        name=sname;
        branch=sbranch;
        phoneNo=sphoneNo;
    }
    void printStudentData()
    {
        System.out.println("Name of the Student :"+ name);
        System.out.println("USN of the Student :"+ usn);
        System.out.println("Branch of the Student :"+ branch);
        System.out.println("Phone No of the Student :"+ phoneNo);
    }
}
public class StudentDemo
{
    public static void main(String [] args)
    {
        int nStudent,ch;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the no of student objects to be created");
        nStudent = in.nextInt();
        Student stud [] = new Student[nStudent];
        while(true)
        {
            System.out.println("1.Create Student Data");
            System.out.println("2.Print Student Data");
            System.out.println("3.Exit");
            ch = in.nextInt();
            switch(ch)
            {
                case 1:
                    for(int i=0;i<nStudent;i++)
                    {
                        System.out.println("Read the Student" + "" +(i+1)+ "Details");
                        in.nextLine();
                        System.out.println("Enter the name of the student");
                        String name = in.nextLine();
                        System.out.println("Enter the usn of the student");
                        String usn = in.nextLine();
                        System.out.println("Enter the branch of the student");
                        String branch = in.nextLine();
                        System.out.println("Enter the phoneNo of the student");
                        long phoneNo = in.nextLong();
                        stud[i] = new Student(name,usn,branch,phoneNo);
                    }
                    break;
                case 2:
                    for(int i=0;i<nStudent;i++)
                    {
                        System.out.println("Details of student" + "" +(i+1)+" is \n");
                        stud[i].printStudentData();
                    }
                    break;
                case 3: 
                    System.exit(0);
                default :System.out.println("Enter the valid choice");
            }
        }
    }
}


