// Remote object
import java.rmi.*;
import java.rmi.server.*;

public class MyRemoteImpl extends UnicastRemoteObject implements MyRemote {
    public MyRemoteImpl() throws RemoteException {}

    public String sayHello() throws RemoteException {
        return "Hello, world!";
    }

    public int add(int a, int b) throws RemoteException {
        return a + b;
    }
}