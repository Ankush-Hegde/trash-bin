import java.util.Scanner;
class Student{
	String usn;
	String name;
	String branch;
	long phoneNo;

Student(String sname,String susn,String sbranch,long sphoneNo){
	usn=susn;
	name=sname;
	branch=sbranch;
	phoneNo=sphoneNo;
}

void printStudentData(){
	System.out.println("Name ofthe student:"+name);
	System.out.println("USN of the student"+usn);
	System.out.println("Branch of the student"+branch);
	System.out.println("Phone No of the student"+phoneNo);
}}
public class StudentDemo{
	public sttic void main(String args[]){
		int nStudent,ch;
		Scanner in=new Scanner(System.in);
		System.out.println("Enter the no of Student object to be created");
		nSTudent= in.nextInt();
		Student stud[]=new Student[nStudent];

		while(true){
			System.out.println("1.create student data");
			System.out.println("print studennt data");
			System.out.println("exit");
			ch=in.nextInt();

			switch(ch)
			{
				case 1:for(int i=0;i<nStudent;i++){

						System.out.println("Read the student"+""+(i+1)+"Details");
								in.nextLine();
						System.out.println("Enter the name of student");
						String name=in.nextLine();
						System.out.println("Enter the usn of student");
						System.out.println("enter the branch of the student");
						String branch=in.nextLine();
						System.out.println("enter the phoneNo of the student");
						long phoneNO=in.nextLong();
						stud[i]=new Student(name,usn,branch,phoneNo)
				}break;
				case 2:for (inyt i=0;i<nStudent;i++){
					       System.out.println("Details of stuident"+""+(i+1)+"is \n");
					       stud[i].printStudentData();
				}
				break;
				case 3:System.exit(0);
				default:System.out.println("Enter the valid choice");
			}
		}
	}
}
