package WazzupClient;

import java.io.*;
import java.net.Socket;

public class WazzupClient {
    private Socket serverSocket;
    private String ipAddr;
    private int port;
    private boolean isConnected;

    public WazzupClient() {
        this.isConnected = false;
        this.ipAddr = "localhost";
        this.port = 8080;
    }

    public void connect() {
        String userLine;
        String serverResponse;

        try {
            System.out.println("Client connecting to server...");
            this.serverSocket = new Socket(this.ipAddr, this.port);
        } catch (IOException e) {
            System.out.println("WazzupClient cannot connect to server.");
            return;
        }
        this.isConnected = true;
        System.out.println("Client connected to server: " + serverSocket.toString().toUpperCase());

        try (BufferedReader in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
             BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter out = new BufferedWriter(new OutputStreamWriter(serverSocket.getOutputStream()));
             BufferedWriter userOutput = new BufferedWriter(new OutputStreamWriter(System.out))) {

            System.out.println(in.readLine());

            while ( ((userLine = userInput.readLine()) != null && !userLine.contains("disconnect")) ) {
                out.write(userLine + "\n");
                out.flush();

                if ( (serverResponse = in.readLine()) == null || serverSocket.isClosed() ) {
                    disconnect();
                    return;
                } else {
                    userOutput.write(serverResponse + "\n");
                    userOutput.flush();
                }
            }
            System.out.println("WazzupClient disconnected.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void disconnect() throws IOException {
        System.out.println("Connection closed by server: " + serverSocket.toString().toUpperCase());
        serverSocket.close();
        this.isConnected = false;
    }

    public static void main(String[] args) {
        WazzupClient wc = new WazzupClient();
        wc.connect();
    }
}
