package downloader;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;


public class Downloader {
    Downloader(String FILE_URL) {
        URL url = null;
        ReadableByteChannel rbc = null;
        FileOutputStream fos = null;

        try {
            url = new URL(FILE_URL);
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return;
        }

        try {
            rbc = Channels.newChannel(url.openStream());
            fos = new FileOutputStream(url.getFile().substring(url.getFile().lastIndexOf('/') + 1));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            fos.getChannel().transferFrom(rbc, 0, Long.MAX_VALUE);
            fos.close();
            rbc.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {
        Downloader down = new Downloader("https://storyfox.ru/wp-content/uploads/2019/07/1_2_1559816747220.jpg");
    }
}
