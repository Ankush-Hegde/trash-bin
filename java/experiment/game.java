import java.io.*;
class game{
        public static void main(String args[])throws IOException{
		int i;
                 i=System.in.read();
               String p ="hlo";
		System.out.println(p); System.out.println("-------------------------------------------------------------------------------");

                System.out.println(i);
        PrintWriter out= new PrintWriter(new File("game.txt"));
        for(i=i;i>0;i--){
     
         out.println(p);       
        out.println(i);

        
        }
                out.close();   System.out.println("-------------------------------------------------------------------------------");

        }
}

