public class Pen {
    private int inkAmount;
    private int inkCapacity;

    public Pen(int inkCapacity) {
        this.inkAmount = inkCapacity;
        this.inkCapacity = inkCapacity;
    }

    public Pen() {
        this(1024); // call Pen(int)
    }

    public int getInkAmount() {
        return inkAmount;
    }
    public int getInkCapacity() {
        return inkCapacity;
    }

    public void write(Paper paper, String message) throws OutOfInkException, OutOfSpaceException {
        if ( inkAmount == 0 ) {
            throw new OutOfInkException();
        }
        if ( message.length() > inkAmount ) {
            paper.addContent(message.substring(0, inkAmount));
            inkAmount = 0;
            return;
        }
        paper.addContent(message);
        inkAmount -= message.length();
    }
    public void refill() {
        inkAmount = inkCapacity;
    }
}