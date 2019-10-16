package echo.EchoServer;

import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.net.Socket;

public class ClientServerHandler extends Thread {
    private Socket clientSocket;

    public ClientServerHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
        start();
    }

    public void run() {
        String clientInput;

        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()))) {

            out.write("HI! Its Sangows' EchoServer! If you wanna exit - type \"disconnect\".\n");
            out.flush();

            while ( (clientInput = in.readLine()) != null && !clientInput.contains("disconnect") ) {
                out.write("Echo: " + clientInput + "\n");
                out.flush();

                System.out.println("Client said: " + clientInput);
            }
        } catch (IOException e) {
            if ( clientSocket.isClosed() ) {
                return;
            }
            e.printStackTrace();
        }

        closeClient();
    }

    public void closeClient() {
        System.out.println("---Client " + clientSocket.toString().toUpperCase() + " disconnected.");
        try {
            clientSocket.close();
            interrupt();
        } catch (IOException e) {
            e.printStackTrace();
        }
        EchoServer.clientList.remove(this);
    }
}
