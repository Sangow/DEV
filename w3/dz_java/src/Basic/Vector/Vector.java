package Basic.Vector;

import static java.lang.Math.hypot;

public class Vector {
    private double x;
    private double y;

    public Vector() {
        this.x = 0;
        this.y = 0;
    }

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double len() {
        return hypot(this.x, this.y);
    }

    public boolean equal(Vector other) {
        return this.x == other.x && this.y == other.y;
    }

    public boolean notEqual(Vector other) {
        return !this.equal(other);
    }

    public void addition(Vector other) {
        this.x += other.x;
        this.y += other.y;
    }

    public void substraction(Vector other) {
        this.x -= other.x;
        this.y -= other.y;
    }

    public Vector sum(Vector other) {
        Vector result = this;

        result.addition(other);
        return result;
    }

    public Vector diff(Vector other) {
        Vector result = this;

        result.substraction(other);
        return result;
    }

    public String toString() {
        return String.format( "(" + this.getX() + ", " + this.getY() + ")" );
    }
}
