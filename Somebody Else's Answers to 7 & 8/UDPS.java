import java.io.*;
import java.net.*;
public class UDPS {
public static void main(String args[]) throws Exception
{
DatagramSocket ds=new DatagramSocket();
InetAddress ip= InetAddress.getByName("localhost");
BufferedReader br=new BufferedReader(new

InputStreamReader(System.in));

int port =2345;
String msg;
while(true)
{
msg=br.readLine();

DatagramPacket dp=new DatagramPacket(msg.getBytes(),msg.length(),ip,port);

if(!msg.equals("quit"))
ds.send(dp);
else
break;

}
}
}
