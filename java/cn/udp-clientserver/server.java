import java.util.*;
import java.net.*;
public class server{
    public static void main(String[] args)throws Exception{
        Scanner in = new Scanner(System.in);
        DatagramSocket sersock = new DatagramSocket(9000);
        byte[] rcvData = new byte[1024];
        byte[] sndData = new byte[1024];
        System.out.println("***server***");
        DatagramPacket rcvpkt = new DatagramPacket(rcvData,rcvData.length);
        sersock.receive(rcvpkt);
        System.out.println(new String(rcvpkt.getData()));
        InetAddress ip=rcvpkt.getAddress();
        int port = rcvpkt.getPort();
        while(true){
            System.out.println("type message to send");
            String message = in.nextLine();
            sndData = message.getBytes();
            System.out.println("                         "+new String(sndData)+"<---");
            //System.out.println("message sent : "+new String(sndData));
            DatagramPacket sndpkt =new DatagramPacket(sndData,sndData.length,ip,port);
            sersock.send(sndpkt);            
        }
    }
}
