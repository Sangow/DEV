// import java.util.Scanner;

public class Loops {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int limit = in.nextInt();

        for ( int i = 0; i < limit; i++ ) {
            System.out.print(i+" ");
        }
        System.out.println(limit);

        in.close();
    }
}
