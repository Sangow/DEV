package EchoServer;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

class EchoServer {
    private ServerSocket ss;
    private Socket cs;
    private BufferedReader in;
    private BufferedWriter out;

    private static final int DEFAULT_PORT = 8080;
    private int serverPort;
    private boolean isRunning;

    public EchoServer() {
        this(DEFAULT_PORT);
    }

    public EchoServer(int port) {
        this.serverPort = port;
        this.isRunning = false;
    }


//        try {
//            try {
//                ss = new ServerSocket(port);
//                System.out.println("Server launched!!!");
//                System.out.println(ss.getLocalSocketAddress().toString());
//                cs = ss.accept();
//
//                try {
//                    in = new BufferedReader(new InputStreamReader(cs.getInputStream()));
//                    out = new BufferedWriter(new OutputStreamWriter(cs.getOutputStream()));
//
//                    String clientText = in.readLine();
//                    System.out.println(clientText);
//
//                    out.write("Hello! Its SERVER! Your message was: " + clientText + "\n");
//                    out.flush();
//                } finally {
//                    System.out.println("Closing in AND out streams.");
//                    in.close();
//                    out.close();
//
//                    System.out.println("Closing clientSocket.");
//                    cs.close();
//                }
//
//            } finally {
//                System.out.println("Closing serverSocket.");
//                ss.close();
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }
    public boolean isRunning() {
        return this.isRunning;
    }

    public int getPort() {
        return this.serverPort;
    }

    public void start() {

    }

    public void stop() {
        this.isRunning = false;
    }

    public static void main(String[] args) {
        EchoServer es = new EchoServer();
//        es.start();
//        es.stop();

//        Scanner sc =  new Scanner(System.in);
//        int dec = sc.nextInt();
//
//        for ( int i = 31; i >= 0; i-- ) {
//            int k = dec >> i;
//            if ( (k & 1) > 0 ) {
//                System.out.print("1");
//            } else {
//                System.out.print("0");
//            }
//        }
    }
}
