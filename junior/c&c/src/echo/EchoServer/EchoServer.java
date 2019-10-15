package echo.EchoServer;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

public class EchoServer implements Runnable {
    static LinkedList<ClientServerHandler> clientList = new LinkedList<>();
    private ServerSocket ss;

    private static final int DEFAULT_PORT = 8080;
    private int serverPort;
    private static boolean isRunning = false;

    public EchoServer() throws IOException {
        this(DEFAULT_PORT);
    }

    public EchoServer(int port) throws IOException {
        this.serverPort = port;
    }

    public boolean isRunning() {
        return isRunning;
    }

    public int getPort() {
        return this.serverPort;
    }

    public void run() {
        ClientServerHandler csh;
        Socket cs = null;
        isRunning = true;

        System.out.println("EchoServer starting...");

        try {
            this.ss = new ServerSocket(serverPort);
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("EchoServer started...");

        while ( isRunning ) {
            System.out.println("Waiting for client...");
            try {
                cs = this.ss.accept();
            } catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println("Client " + cs.toString() + " connected.");
            csh = new ClientServerHandler(cs);
            clientList.add(csh);
            csh.start();
        }

//            System.out.println("Client connected: " + cs.toString());
//
//            try ( BufferedReader in = new BufferedReader(new InputStreamReader(cs.getInputStream()));
//                   BufferedWriter out = new BufferedWriter(new OutputStreamWriter(cs.getOutputStream()));) {
//                String clientInput;
//
//                while ( (clientInput = in.readLine()) != null && !clientInput.contains("disconnect") ) {
//                    System.out.println("Client said: " + clientInput);
//                    out.write("Echo: " + clientInput + "\n");
//                    out.flush();
//                }
//                System.out.println("Client gone...");
//
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }
    }

    public void stop() {
        this.isRunning = false;
    }
}
