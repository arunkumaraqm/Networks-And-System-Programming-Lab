import java.io.*;
import java.net.*;
public class UDPC {
public static void main(String args[]) throws Exception
{
DatagramSocket ds=new DatagramSocket(2345);
String msg;

byte[] buf=new byte[100];
while(true)
{
DatagramPacket rdp=new
DatagramPacket(buf,buf.length);
ds.receive(rdp);
msg=new String(rdp.getData(),rdp.getOffset(),rdp.getLength());
System.out.println(msg);
}
}
}
