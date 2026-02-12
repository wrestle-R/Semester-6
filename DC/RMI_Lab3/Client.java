import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_RED = "\u001B[31m";

    public static void main(String[] args) {
        try {
            System.out.println(ANSI_BLUE + "\n==============================");
            System.out.println("   JAVA RMI CLIENT STARTING   ");
            System.out.println("==============================" + ANSI_RESET);
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            MyRemote stub = (MyRemote) registry.lookup("CalculatorService");
            int sum = stub.add(10, 20);
            System.out.println(ANSI_GREEN + "\n 10 + 20 = " + sum + ANSI_RESET);
        } catch (Exception e) {
            System.out.println(ANSI_RED + "[✖] Failed to connect to server!" + ANSI_RESET);
            e.printStackTrace();
        }
    }
}
