package httpServer;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.Instant;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;

public class ClientHandler extends Thread {
    private Socket clientSocket;

    private String DEFAULT_FILE     = "index.html";
    private String FILE_NOT_FOUND   = "not_found.html";
    private String NOT_ALLOWED      = "method_not_allowed.html";

    ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
        start();
    }

    @Override
    public void run() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(this.clientSocket.getInputStream()));
             PrintWriter pr = new PrintWriter(this.clientSocket.getOutputStream())) {
            String[] parts;

            if ( (parts = this.parseClientRequest(br.readLine())) == null ) {
                clientSocket.close();
                return;
            }

            this.send(pr, parts[0].toUpperCase(), parts[1]);
            clientSocket.close();
        } catch (IOException ioe) {
            System.err.println(ioe.getMessage());
        }
    }

    private void send(PrintWriter pr, String method, String requestedFile) throws IOException {
        switch ( this.identifyRequest(method, requestedFile) ) {
            case "OK" :
                this.sendResponse(pr, 200, "OK", getContentType(requestedFile),
                        requestedFile, (int) Files.size(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + requestedFile)));
                System.out.println("200 " + requestedFile);
                break;
            case "DEFAULT" :
                this.sendResponse(pr, 200, "OK", getContentType(DEFAULT_FILE),
                        DEFAULT_FILE, (int) Files.size(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + DEFAULT_FILE)));
                System.out.println("200 " + requestedFile);
                break;
            case "NOT_ALLOWED" :
                this.sendResponse(pr, 405, "Not Allowed Method", getContentType(NOT_ALLOWED),
                        NOT_ALLOWED, (int) Files.size(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + NOT_ALLOWED)));
                System.out.println("405 " + requestedFile);
                break;
            case "NOT_FOUND" :
                this.sendResponse(pr, 404, "Not Found", getContentType(FILE_NOT_FOUND),
                        FILE_NOT_FOUND, (int) Files.size(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + FILE_NOT_FOUND)));
                System.out.println("404 " + requestedFile);
                break;
        }
    }

    private String[] parseClientRequest(String request) throws IOException {
        if ( request == null || request.equals("") ) {
            return null;
        }
        String[] parts = request.split("\\s");

        if (parts.length < 3) {
            return null;
        }

        return parts;
    }

    private String identifyRequest(String method, String requestedFile) {
        if ( method.equals("GET") ) {
            if ( requestedFile.equals("/") ) {
                return "DEFAULT";
            }

            if (Files.exists(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + requestedFile)) &&
                    !Files.isDirectory(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + requestedFile))) {
                return "OK";
            }
            return "NOT_FOUND";
        }
        return "NOT_ALLOWED";
    }

    private String getContentType(String fileRequested) {
        String extension = fileRequested.substring(fileRequested.lastIndexOf(".") + 1);

        if ( HttpServer.mimes.containsKey(extension) ) {
            return HttpServer.mimes.get(extension);
        }
        return "application/octet-stream";
    }

    private void sendResponse(PrintWriter pr, int statusCode, String statusDesc, String mimeType, String fileName, int contentLength) throws IOException {
        this.sendHeader(pr, statusCode, statusDesc, mimeType, contentLength);
        this.sendContent(fileName);
    }

    private void sendHeader(PrintWriter pr, int statusCode, String statusDesc, String mimeType, int contentLength) {
        pr.println("HTTP/1.1 " + statusCode + " " + statusDesc);
        pr.println("Connection: Close");
        pr.println("Content-Length: " + contentLength);
        pr.println("Content-Type: " + mimeType);
        pr.println("Date: " + DateTimeFormatter.RFC_1123_DATE_TIME.withZone(ZoneOffset.UTC).format(Instant.now()));
        pr.println();
        pr.flush();
    }

    private void sendContent(String fileName) throws IOException {
        Files.copy(Paths.get(HttpServer.WORKING_DIRECTORY + HttpServer.WEB_DIRECTORY + fileName), this.clientSocket.getOutputStream());
    }
}