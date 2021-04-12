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

/*DatagramSocket() throws SocketEeption: it creates a datagram socket and binds it with the available Port Number on the localhost machine.
DatagramSocket(int port) throws SocketEeption: it creates a datagram socket and binds it with the given Port Number.
DatagramSocket(int port, InetAddress address) throws SocketEeption: it creates a datagram socket and binds it with the specified port number and host address.
*/
/*DatagramPacket(byte[] barr, int length): it creates a datagram packet. This constructor is used to receive the packets.
DatagramPacket(byte[] barr, int length, InetAddress address, int port): it creates a datagram packet. This constructor is used to send the packets.
*/

public class MyServer
{

	public static void main(String[] args) throws Exception
	{
		int port = 9994;
		String host = "localhost";

		DatagramSocket dg_sock = new DatagramSocket();
		InetAddress ip = InetAddress.getByName(host);

		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));

		// send every line that user enters as a packet to the client process
		while (true)
		{
			String msg = cin.readLine();
			DatagramPacket packet = new DatagramPacket(
				msg.getBytes(),
				msg.length(),
				ip,
				port
			);
			dg_sock.send(packet);

			if (msg.equals("quit")) // message == "quit" will not work
			{
				break;
			}

		}

		dg_sock.close();


	}
}
