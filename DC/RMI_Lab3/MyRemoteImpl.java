import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class MyRemoteImpl extends UnicastRemoteObject implements MyRemote {

    protected MyRemoteImpl() throws RemoteException {
        super();
    }

    public String sayHello() throws RemoteException {
        return "Hello from Server!";
    }

    public int add(int a, int b) throws RemoteException {
        return a + b;
    }
}
