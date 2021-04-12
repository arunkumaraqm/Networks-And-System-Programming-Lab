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
io in java
InputStream::read reads a single byte and returns it as an int while InputStreamReader::read reads a single char (respecting the encoding) and returns this as an int. If you're reading big chunks of text, you can even wrap the InputStreamReader in a BufferedReader which provides you with some nice methods to let's say read whole lines at once
*/

public class MyServer
{

	public static void main(String[] args) throws IOException
	{

/*	From Beej's Guide
Another thing to watch out for when callingbind(): don’t go underboard with your port numbers. Allports below 1024 are RESERVED (unless you’re the superuser)! You can have any port number abovethat, right up to 65535 (provided they aren’t already being used by another program).

Sometimes, you might notice, you try to rerun a server andbind()fails, claiming “Address already inuse.” What does that mean? Well, a little bit of a socket that was connected is still hanging around in thekernel, and it’s hogging the port. You can either wait for it to clear (a minute or so), or add code to your program allowing it to reuse the port.
		ServerSocket ser_sock = new ServerSocket(); // don't bind just yet
		ser_sock.setReuseAddress(true);
		ser_sock.bind(new InetSocketAddress("localhost", 9996));
It turns out that this doesn't solve my problem at all.
The solution to BindException is to never send SIGKILL, only send SIGINT. If you do get a BindException, change your port address on both programs.
*/

		ServerSocket ser_sock = new ServerSocket(9996); // random port number to bind to
		// bind and listen are called implicitly

		System.out.println("server scoket initia");

		Socket sock = ser_sock.accept(); // returns reference to new socket on the server that is connected to the client's socket
		System.out.println("server socket accepted");

		// Each Socket object has an input stream and an output stream
		InputStream sockets_input_stream = sock.getInputStream();
		BufferedReader sin = new BufferedReader(new InputStreamReader(sockets_input_stream));

		OutputStream sockets_output_stream = sock.getOutputStream();
		PrintWriter sout = new PrintWriter(sockets_output_stream, true); // autoflush set to true

		System.out.println("BufferedReader & PrintWriter initialized.");

		// Read the filename sent by client
		String given_file_name = sin.readLine();

		// Open that file
		BufferedReader fin = new BufferedReader(new FileReader(given_file_name));

		// Print the contents of the file and also send them to client
		while (true)
		{
			String msg = fin.readLine();
			if (msg == null)
			{
				break;
			}
			else
			{
				System.out.println(msg + "$");
				sout.println(msg);
			}
		}

		sock.close();


	}
}
