public class Paper {
    private int maxSymbols;
    private int symbols;
    private StringBuffer content;

    public Paper() {
        this.maxSymbols = 4096;
        this.symbols = 0;
        content = new StringBuffer();
    }

    public Paper(int maxSymbols) {
        this.maxSymbols = maxSymbols;
        this.symbols = 0;
        content = new StringBuffer();
    }

    public int getMaxSymbols() {
        return maxSymbols;
    }

    public int getSymbols() {
        return symbols;
    }

    public StringBuffer getContent() {
        return content;
    }

    public void addContent(String message) throws OutOfSpace {
        int maxInputSymbols = this.maxSymbols - this.symbols;

        if (this.symbols == this.maxSymbols ) {
            throw new OutOfSpace();
        }

        if ( maxInputSymbols < message.length() ) {
            this.symbols = this.maxSymbols;
            this.content.append(message.substring(0, maxInputSymbols));
            return;
        }
        this.symbols += message.length();
        this.content.append(message);
    }

    public void show() {
        System.out.println(this.getContent());
    }
}
