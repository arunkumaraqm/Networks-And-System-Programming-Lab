import java.net.*;
import java.io.*;

/*
Server 
socket()
bind()
listen()
accept()
read()
write()

Client
socket()
connect()
write()
read()
*/

/*
	Socket()
Creates an unconnected socket, with the system-default type of SocketImpl.
 	Socket(InetAddress address, int port)
Creates a stream socket and connects it to the specified port number at the specified IP address.
*/
public class MyClient
{

	public static void main(String[] args) throws IOException
	{
		Socket sock = new Socket("localhost", 9996);
		// connect called implicitly

		// Each Socket object has an input stream and an output stream
		InputStream sockets_input_stream = sock.getInputStream();
		BufferedReader sin = new BufferedReader(new InputStreamReader(sockets_input_stream));
		OutputStream sockets_output_stream = sock.getOutputStream();
		PrintWriter sout = new PrintWriter(sockets_output_stream, true); // autoflush set to true

		// Take the filename as input from user
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		String given_file_name = cin.readLine();
		System.out.println("received input" + given_file_name);

		// Send the filename to server
		sout.println(given_file_name);


		// Read the content that server sends and print to console
		while (true)
		{
			String msg = sin.readLine();
			if (msg == null)
			{
				break;
			}
			else
			{
				System.out.println(msg + "$");
			}
		}
	}
}
