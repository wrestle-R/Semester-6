
import java.io.*;
import java.net.*;
import java.util.*;

public class MultiServer {

    private static Set<PrintWriter> clients = new HashSet<>();

    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(6000);

        while (true) {
            Socket socket = serverSocket.accept();
            new ClientHandler(socket).start();
        }
    }

    static class ClientHandler extends Thread {

        private Socket socket;
        private PrintWriter out;
        private BufferedReader in;

        ClientHandler(Socket socket) throws Exception {
            this.socket = socket;
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            synchronized (clients) {
                clients.add(out);
            }
        }

        public void run() {
            String message;
            try {
                while ((message = in.readLine()) != null) {
                    synchronized (clients) {
                        for (PrintWriter client : clients) {
                            client.println(message);
                        }
                    }
                }
            } catch (Exception e) {
            } finally {
                try {
                    socket.close();
                } catch (Exception e) {
                }
                synchronized (clients) {
                    clients.remove(out);
                }
            }
        }
    }
}
