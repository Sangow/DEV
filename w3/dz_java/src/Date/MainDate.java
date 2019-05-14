public class MainDate {
    public static void main(String[] args) {
        try {
            Date date = new Date(15, 2, 1997);

            System.out.println(date);

            System.out.println(date.getDay());

        } catch ( InvalidDate e ) {
            System.out.println(e.text);
        }
    }
}
