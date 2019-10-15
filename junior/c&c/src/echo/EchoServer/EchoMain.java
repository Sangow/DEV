package echo.EchoServer;

import java.io.IOException;

public class EchoMain {
    public static void main(String[] args) throws IOException {
        EchoServer es = new EchoServer();
        Thread server = new Thread(es);

        server.start();
    }
}