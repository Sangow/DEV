package echo.EchoServer;

import java.io.*;
import java.net.Socket;
import java.io.BufferedWriter;
import java.io.BufferedReader;

public class ClientServerHandler extends Thread {
    private Socket clientSocket = null;
//    Buffered echo = null;
//    BufferedReader in = null;

    public ClientServerHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    public void run() {
        String clientInput;
        BufferedReader in = null;
        BufferedWriter out = null;

        try {
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
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

        System.out.println("Client " + clientSocket.toString() + " disconnected.");
        try {
            clientSocket.close();
            interrupt();
        } catch (IOException e) {
            e.printStackTrace();
        }
        EchoServer.clientList.remove(this);



//        System.out.println("ZALUPA!!!");
//
//        try ( BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
//                BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())) ) {
//            while ( (clientInput = in.readLine()) != null && !clientInput.contains("disconnect") ) {
//                out.write("Echo: " + clientInput);
//                out.flush();
//
//                System.out.println("Client said: " + clientInput);
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//
//        try {
//            System.out.println("Client: " + clientSocket.toString() + " gone.");
//            clientSocket.close();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        EchoServer.clientList.remove(this);
    }

}
