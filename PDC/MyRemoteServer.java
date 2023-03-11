// Server program
import java.rmi.*;

public class MyRemoteServer {
    public static void main(String[] args) {
        try {
            MyRemoteImpl remoteObj = new MyRemoteImpl();
            Naming.rebind("MyRemoteObject", remoteObj);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}