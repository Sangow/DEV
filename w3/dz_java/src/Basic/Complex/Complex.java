package Basic.Complex;

public class Complex {
    private double real;
    private double imaginary;

    public Complex() {
        this.real = 0;
        this.imaginary = 0;
    }

    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() {
        return this.real;
    }

    public double getImaginary() {
        return this.imaginary;
    }

    public boolean equal(Complex other) {
        return this.real == other.real && this.imaginary == other.imaginary;
    }

    public boolean notEqual(Complex other) {
        return !this.equal(other);
    }

    public void addition(Complex other) {
        this.real += other.real;
        this.imaginary += other.imaginary;
    }

    public void substraction(Complex other) {
        this.real -= other.real;
        this.imaginary -= other.imaginary;
    }

    public Complex sum(Complex other) {
        Complex result = this;

        result.addition(other);
        return result;
    }

    public Complex diff(Complex other) {
        Complex result = this;

        result.substraction(other);
        return result;
    }

    public Complex multiple(Complex other) {
        Complex result = this;

        result.real = this.real * other.real;
        result.imaginary = this.imaginary * other.imaginary;
        return result;
    }

    public String toString() {
        if ( this.getImaginary() < 0 ) {
            return String.format( this.getReal() + this.getImaginary() + "i" );
        } else {
            return String.format( this.getReal() + "+" + this.getImaginary() );
        }
    }
}
