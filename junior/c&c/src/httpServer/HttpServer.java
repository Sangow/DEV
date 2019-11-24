package httpServer;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;
import java.net.ServerSocket;

public class HttpServer implements Runnable {
    protected static int PORT;
    protected static String ADDRESS;
    protected static String WEB_DIRECTORY;

    protected static String WORKING_DIRECTORY = new File("").getAbsolutePath() + "/src/httpServer/";
    protected static String CONF_FILE = "http.conf";
    protected static String MIME_FILE = "mime.types";

    protected static boolean isRunning = false;

    protected static HashMap<String, String> mimes;

    static void getMimeTypes() {
        mimes = new HashMap<>();

        try (Scanner sc = new Scanner(new FileReader(WORKING_DIRECTORY + MIME_FILE))) {
            while ( sc.hasNextLine() ) {
                String str = sc.nextLine().trim();

                if ( !str.equals("") ) {
                    mimes.put(str.substring(0, str.indexOf(" ")), str.substring(str.indexOf(" ")).trim());
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    HttpServer() throws FileNotFoundException {
        try (Scanner sc = new Scanner(new FileReader(WORKING_DIRECTORY + CONF_FILE))) {
            while (sc.hasNextLine()) {
                String temp = sc.nextLine().trim();

                switch ( temp.substring(0, temp.indexOf(" ")) ) {
                    case "address":
                        ADDRESS = temp.substring(temp.indexOf(" ")).trim();
                        break;
                    case "port":
                        PORT = Integer.parseInt(temp.substring(temp.indexOf(" ")).trim());
                        break;
                    case "root_dir":
                        WEB_DIRECTORY = temp.substring(temp.indexOf(" ")).trim();
                        break;
                }
            }
        }
        HttpServer.getMimeTypes();
    }

    @Override
    public void run() {
        try (ServerSocket ss = new ServerSocket(PORT)) {
            isRunning = true;

            while ( isRunning ) {
                new ClientHandler(ss.accept());
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