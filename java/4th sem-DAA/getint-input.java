import java.util.Scanner;

class input{
	public static void main(String args[]){
		Scanner input =new Scanner(System.in);
		System.out.print("Enter an integer : ");
		int number=input.nextInt();
		System.out.println("you entered : "+number);

		//closing the scanner object
		input.close();
	}
}
