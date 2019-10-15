package echo.EchoServer.WazzupClient;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.net.Socket;

public class WazzupClient {
    private Socket clientSocket;
    private BufferedReader reader;
    private BufferedReader in;
    private BufferedWriter out;

    public WazzupClient() {
        try {
            try {
                this.clientSocket = new Socket("localhost", 8080);
            } finally {
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}