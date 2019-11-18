package EchoServer;

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

    @Override
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
                if ( ss.isClosed() ) {
                    return;
                }
                e.printStackTrace();
            }

            System.out.println("---Client " + cs.toString().toUpperCase() + " connected.");
            clientList.add(new ClientServerHandler(cs));
        }
    }

    public void stop(Thread echoServer) throws IOException {
        if ( isRunning ) {

            while ( !clientList.isEmpty() ) {
                clientList.getFirst().closeClient();
            }

            ss.close();
            echoServer.interrupt();
            isRunning = false;

            System.out.println("ServerSocket closed.");
        }
    }
}
