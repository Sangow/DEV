package httpServer;

import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.Instant;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class ClientHandler extends Thread {
    private Socket clientSocket;
    private String WORKING_DIRECTORY;
    private String WEB_DIRECTORY;

    private String DEFAULT_FILE     = "index.html";
    private String FILE_NOT_FOUND   = "not_found.html";
    private String NOT_ALLOWED      = "method_not_allowed.html";
    private String MIME_FILE        = "mime.types";

    ClientHandler(Socket clientSocket, String workingDirectory, String webDirectory) {
        this.clientSocket = clientSocket;
        this.WORKING_DIRECTORY = workingDirectory;
        this.WEB_DIRECTORY = webDirectory;
        start();
    }

    @Override
    public void run() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(this.clientSocket.getInputStream()));
             PrintWriter pr = new PrintWriter(this.clientSocket.getOutputStream())) {

            String line;
            if ((line = br.readLine()) == null) {
                clientSocket.close();
                return;
            }

            String[] parts = line.split("\\s");

            if (parts.length < 3) {
                clientSocket.close();
                return;
            }

            String method = parts[0].toUpperCase();;
            String requestedFile = parts[1].toLowerCase();

            if (!method.equals("GET")) {
                this.sendResponse(pr, 405, "Not Allowed Method", getMimeType(NOT_ALLOWED),
                        requestedFile, (int) Files.size(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + NOT_ALLOWED)));

                System.out.println("405 " + requestedFile);
            } else { // GET method OK
                if (requestedFile.equals("/")) {
                    requestedFile += DEFAULT_FILE;
                }

                if (Files.exists(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + requestedFile)) &&
                    !Files.isDirectory(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + requestedFile))) {
                    this.sendResponse(pr, 200, "OK", getMimeType(requestedFile),
                            requestedFile, (int) Files.size(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + requestedFile)));

                    System.out.println("200 " + requestedFile);
                } else { // GET method, no FILE_NOT_FOUND
                    this.sendResponse(pr, 404, "Not Found", getMimeType(FILE_NOT_FOUND),
                            FILE_NOT_FOUND, (int) Files.size(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + FILE_NOT_FOUND)));

                    System.out.println("404 " + requestedFile);
                }
            }
            clientSocket.close();
        } catch (IOException ioe) {
            System.err.println(ioe.getMessage());
        } catch (NullPointerException npe) {
            npe.printStackTrace();
        }
    }

    private String getMimeType(String fileRequested) throws FileNotFoundException {
        String extension = fileRequested.substring(fileRequested.lastIndexOf(".") + 1);
        Scanner sc = new Scanner(new FileReader(WORKING_DIRECTORY + MIME_FILE));

        if (!extension.equals("")) {
            while (sc.hasNextLine()) {
                String str = sc.nextLine();

                if (!str.equals("")) {
                    String mimeExctension = str.substring(0, str.indexOf(" ")).trim();

                    if (mimeExctension.equals(extension)) {
                        return str.substring(mimeExctension.length()).trim();
                    }
                }
            }
        }
        sc.close();
        return "application/octet-stream";
    }

    private void sendResponse(PrintWriter pr, int statusCode, String statusDesc, String mimeType, String fileName, int contentLength) throws IOException {
        // send header
        pr.println("HTTP/1.1 " + statusCode + " " + statusDesc);
        pr.println("Connection: Close");
        pr.println("Content-Length: " + contentLength);
        pr.println("Content-Type: " + mimeType);
        pr.println("Date: " + DateTimeFormatter.RFC_1123_DATE_TIME.withZone(ZoneOffset.UTC).format(Instant.now()));
        pr.println();
        pr.flush();

        //send content
        Files.copy(Paths.get(WORKING_DIRECTORY + WEB_DIRECTORY + fileName), this.clientSocket.getOutputStream());
    }
}