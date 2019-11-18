import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.net.ServerSocket;
import java.util.Scanner;
import java.util.StringTokenizer;

public class HttpServer implements Runnable {
    private int PORT;
    private String ADDRESS;
    private String WEB_DIRECTORY;

    private String WORKING_DIRECTORY = new File("").getAbsolutePath() + "/";
    private String CONF_FILE = "http.conf";

    private static boolean isRunning = false;

    HttpServer() throws FileNotFoundException {
        StringTokenizer st;
        try (Scanner sc = new Scanner(new FileReader(WORKING_DIRECTORY + CONF_FILE))) {
            while (sc.hasNextLine()) {
                st = new StringTokenizer(sc.nextLine());
                String temp = st.nextToken();

                if (temp.equals("address")) {
                    ADDRESS = st.nextToken();
                } else if (temp.equals("port")) {
                    PORT = Integer.parseInt(st.nextToken());
                } else if (temp.equals("root_dir")) {
                    WEB_DIRECTORY = st.nextToken();
                }
            }
        }
    }

    @Override
    public void run() {
        try (ServerSocket ss = new ServerSocket(PORT)) {
            isRunning = true;

            while ( isRunning ) {
                new ClientHandler(ss.accept(), WORKING_DIRECTORY, WEB_DIRECTORY);
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        HttpServer hs = null;

        try {
            hs = new HttpServer();
        } catch (FileNotFoundException e) {
            System.err.println(e.getMessage());;
        }

        new Thread(hs).start();
    }
}
