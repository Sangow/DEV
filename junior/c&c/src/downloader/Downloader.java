package downloader;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.util.Scanner;


public class Downloader {
    Downloader() {
        URL url;
        ReadableByteChannel rbc = null;
        FileOutputStream fos = null;
        String fileName;

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter URL address: ");
        try {
            url = new URL(sc.nextLine());
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }

        fileName = url.getFile().substring(url.getFile().lastIndexOf('/') + 1);

        try {
            rbc = Channels.newChannel(url.openStream());
            fos = new FileOutputStream(fileName);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            System.out.println("Downloading: \"" + fileName + "\" file.");
            fos.getChannel().transferFrom(rbc, 0, Long.MAX_VALUE);
            fos.close();
            rbc.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("File: \"" + fileName + "\" successfully stored.");
    }
}
