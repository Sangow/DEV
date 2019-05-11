public class Strings {
    public static void main(String[] args) {
        StringBuffer out = new StringBuffer();

        for ( int i = 0; i < 10; i++ ) {
            out.append("some text...");
        }

        System.out.println(out);
    }
}