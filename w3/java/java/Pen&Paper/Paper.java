public class Paper {
    private StringBuffer content;
    private int maxSymbols;

    public Paper(int maxSymbols) {
        this.maxSymbols = maxSymbols;
        content = new StringBuffer();
    }

    public Paper() {
        this(4096); // call Paper(int)
    }

    public int getMaxSymbols() {
        return maxSymbols;
    }

    public void addContent(String message) throws OutOfSpaceException {
        int total = content.length() + message.length();

        if ( content.length() == maxSymbols ) {
            throw new OutOfSpaceException();
        }
        if ( total > maxSymbols ) {
            content.append(message.substring(0, maxSymbols-content.length()));
            return;
        }
        content.append(message);
    }
    public void show() {
        System.out.println(content);
    }
}