package PenPaper;

public class Pen {
    private int inkAmount;
    private int inkCapacity;

    public Pen() {
        this.inkCapacity = 4096;
        this.inkAmount = inkCapacity;
    }

    public Pen(int inkCapacity) {
        this.inkCapacity = inkCapacity;
        this.inkAmount = inkCapacity;
    }

    public int getInkAmount() {
        return inkAmount;
    }

    public int getInkCapacity() {
        return inkCapacity;
    }

    public void write(Paper paper, String message) throws OutOfInk, OutOfSpace {
        if ( this.inkAmount == 0 ) {
            throw new OutOfInk();
        }
        if ( this.inkAmount < message.length() ) {
            int newLength = this.inkAmount;

            this.inkAmount = 0;
            paper.addContent(message.substring(0, newLength));
            return;
        }
        this.inkAmount -= message.length();
        paper.addContent(message);
    }

    public void refill() {
        this.inkAmount = this.inkCapacity;
    }
}
