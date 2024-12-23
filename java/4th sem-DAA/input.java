import java.util.Scanner;

class input{
	public static void main(String args[]){
		Scanner input =new Scanner(System.in);
		
		//System.out.print("Enter an integer : ");
		//int number=input.nextInt();
		//System.out.println("you entered : "+number);

		//System.out.print("\n Enter double");
	        //double a=input.nextDouble();
	        //System.out.print("\nentered is"+a);
		
		//System.out.print("enter float ");
		//float b=input.nextFloat();
		//System.out.println("\n entery"+b);

		//System.out.print("\nstring ");
		//String dump=input.next();
		//System.out.println("\n entery "+dump);

		System.out.print("\n line");
		String dum=input.nextLine();
		System.out.println("\n entered "+dum);

		//clossing the scanner object
		input.close();
	}
}
