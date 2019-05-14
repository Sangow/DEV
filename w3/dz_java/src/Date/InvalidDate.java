public class InvalidDate extends Exception {
    public String text;

    public InvalidDate(String text) {
        this.text = text;
    }
}
