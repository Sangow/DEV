public class PPMain {
    public static void main(String[] args) throws OutOfInkException, OutOfSpaceException {
        Paper paper = new Paper();
        Pen pen = new Pen();

        pen.write(paper, "Hello, world!");
        paper.show();
    }
}