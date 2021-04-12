import java.net.*;
import java.io.*;

/*
Server 
socket()
bind()
recvfrom()
sendto()
close()

Client
socket()
bind() optional
sendto()
recvfrom()
close()
*/

public class MyClient
{

	public static void main(String[] args) throws Exception
	{
		int port = 9994;
		String host = "localhost";

		DatagramSocket dg_sock = new DatagramSocket(port);

		byte[] buf = new byte[32];
		while (true)
		{
			DatagramPacket received_packet = new DatagramPacket(buf, buf.length);
			dg_sock.receive(received_packet);

			String message = new String(
				received_packet.getData(),
				received_packet.getOffset(),
				received_packet.getLength()
			);

			System.out.println(message);

			if (message.equals("quit")) 
			{
				break;	
			}
		}

		dg_sock.close();
	}
}
