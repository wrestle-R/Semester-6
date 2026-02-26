
import java.io.*;
import java.net.*;

public class MultiClient {

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", 6000);

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        new Thread(() -> {
            try {
                String response;
                while ((response = in.readLine()) != null) {
                    System.out.println(response);
                }
            } catch (Exception e) {
            }
        }).start();

        String message;
        while ((message = userInput.readLine()) != null) {
            out.println(message);
        }
    }
}
