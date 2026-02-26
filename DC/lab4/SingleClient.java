
import java.io.*;
import java.net.*;

public class SingleClient {

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", 5000);

        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        String message;
        while ((message = userInput.readLine()) != null) {
            out.println(message);
            if (message.equalsIgnoreCase("exit")) {
                break;
            }
        }

        socket.close();
    }
}
