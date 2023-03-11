// Remote interface
import java.rmi.*;

public interface MyRemote extends Remote {
    public String sayHello() throws RemoteException;
    public int add(int a, int b) throws RemoteException;
}