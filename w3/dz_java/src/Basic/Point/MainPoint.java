public class MainPoint {
    public static void main(String[] args) {
        Point p1 = new Point(1,4);
        Point p2 = new Point(5, 10);

        System.out.println(p1.distance(p2));

        System.out.println(p1.equal(p2));
        System.out.println(p1.notEqual(p2));

        System.out.println(p1);

    }
}
