import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_YELLOW = "\u001B[33m";

    public static void main(String[] args) {
        try {
            System.out.println(ANSI_CYAN + "\n==============================");
            System.out.println("   JAVA RMI SERVER STARTING   ");
            System.out.println("==============================" + ANSI_RESET);
            MyRemoteImpl obj = new MyRemoteImpl();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("CalculatorService", obj);
            System.out.println(ANSI_GREEN + "\n Server ready and listening on port 1099!" + ANSI_RESET);
            System.out.println(ANSI_YELLOW + "[i] Press Ctrl+C to stop the server." + ANSI_RESET);
        } catch (Exception e) {
            System.out.println("\u001B[31m[✖] Server failed to start!\u001B[0m");
            e.printStackTrace();
        }
    }
}
