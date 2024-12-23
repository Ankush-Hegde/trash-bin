import java.net.*;
public class client{
    public static void main(String[] args)throws Exception{
        String line ="connected with client";
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress IpAddress = InetAddress.getByName("localhost");
        byte[] sendData = new byte[1024];
        byte[] reciveData = new byte[1024];
        sendData = line.getBytes();
        DatagramPacket sndpkt = new DatagramPacket(sendData,sendData.length,IpAddress,9000);
        clientSocket.send(sndpkt);
        System.out.println("***client Display terminal***");
        while(true){
            DatagramPacket rcvpkt = new DatagramPacket(reciveData,reciveData.length);
            clientSocket.receive(rcvpkt);
            String messgrecv = new String(rcvpkt.getData(),rcvpkt.getOffset(),rcvpkt.getLength());
            System.out.println("--> "+messgrecv);
            //System.out.println("message recived is "+messgrecv);
        }
    }    
}
