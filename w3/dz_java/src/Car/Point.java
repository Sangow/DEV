import static java.lang.Math.hypot;

public class Point {
    private double x;
    private double y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point (double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double distance(Point other) {
        return hypot(this.x - other.x, this.y - other.y);
    }

    boolean equal(Point other) {
        return this.x == other.x && this.y == other.y;
    }

    boolean notEqual(Point other) {
        return !this.equal(other);
    }

    @Override
    public String toString() {
        return String.format("(" + this.getX() + ", " + this.getY() + ")");
    }
}
