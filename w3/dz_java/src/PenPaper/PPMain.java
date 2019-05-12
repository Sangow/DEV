package PenPaper;

public class PPMain {
    public static void main(String[] args) {
        Pen pen = new Pen(20);
        Paper paper = new Paper(40);

        try {
            pen.refill();

            pen.write(paper, "Hello, world!");
            paper.show();

            pen.write(paper, " Come over to the dark side!");
            paper.show();

            pen.refill();

            pen.write(paper, "ver to the dark side!");
            paper.show();

            pen.refill();

            pen.write(paper, "This text will not be printed!");

        } catch (OutOfSpace e) {
            System.out.println("Out of Space!");
        } catch (OutOfInk e) {
            System.out.println("Out of Ink!");
        }
    }
}
