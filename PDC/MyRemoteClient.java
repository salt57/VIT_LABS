// Client program
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class MyRemoteClient {

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry();
            MyRemote stub = (MyRemote) registry.lookup("MyRemoteObject");
            System.out.println(stub.sayHello());
            int result = stub.add(2, 3);
            System.out.println("Result: " + result);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

}