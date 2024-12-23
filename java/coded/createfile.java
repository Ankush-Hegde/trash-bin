import java.io.*;
class createfile{
        public static void main(String args[])throws IOException{
		int i;
		String p ="THIS IS DECREMENT OF ASCII VALUE OF CHARACTER U TYPED";
                 i=System.in.read();
                System.out.println("-------------------------------------------------------------------------------");

                System.out.println(i);
        PrintWriter out= new PrintWriter(new File("createfile.txt"));
        out.println(p); 
        for(i=i;i>0;i--){
        
            
        out.println((char)i);
        out.println(i);

        
        }
                out.close();   System.out.println("-------------------------------------------------------------------------------");

        }
}

