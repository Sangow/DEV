package EchoServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EchoMain {
    public static void main(String[] args) throws IOException {
        EchoServer echoServer = new EchoServer();
        Thread serverThread = new Thread(echoServer);

        serverThread.start();

        BufferedReader adminInput = new BufferedReader(new InputStreamReader(System.in));
        String adminCommand;

        while ( (adminCommand = adminInput.readLine()) != null && !adminCommand.contains("stop") ) {
            System.out.println("Admin said: " + adminCommand);
        }
        echoServer.stop(serverThread);
    }
}
