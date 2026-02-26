
import java.io.*;
import java.net.*;

public class SingleServer {

    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(5000);
        Socket socket = serverSocket.accept();

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        String message;
        while ((message = in.readLine()) != null) {
            System.out.println("Client: " + message);
        }

        socket.close();
        serverSocket.close();
    }
}
