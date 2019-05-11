public class Point implements Cloneable {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        this(0.0, 0.0);
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double value) {
        x = value;
    }

    public void setY(double value) {
        y = value;
    }

    public boolean equals(Point other) {
        return x == other.x && y == other.y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public double distance(Point other) {
        return Math.hypot(x-other.x, y-other.y);
    }

    public Point clone() throws CloneNotSupportedException {
        return (Point) super.clone();
    }
}
