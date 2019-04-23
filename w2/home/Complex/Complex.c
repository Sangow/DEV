#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} Complex;

void complexIncrement(Complex *this, Complex other) {
    this->re += other.re;
    this->im += other.im;
}

void complexDecrement(Complex *this, Complex other) {
    this->re -= other.re;
    this->im -= other.im;
}

void complexMultiply(Complex *this, Complex other) {
    Complex mult;
    
    mult.re = this->re * other.re - this->im * other.im;
    mult.im = this->re * other.im + this->im * other.re;
    this->re = mult.re;
    this->im = mult.im;
}

// !!! Нельзя использовать, т.к. "this->re" перезаписывается на 31 строке и используется на 32 !!!
//--------------------------------------------------------//
// void complexMultiply(Complex *this,Complex other) {
//     this->re = this->re * other.re - this->im * other.im;
//     this->im = this->re * other.im + this->im * other.re;
// }

Complex complexSum(Complex a, Complex b) {
    Complex sum = a;
    
    complexIncrement(&sum, b);
    return sum;
}

Complex complexDiff(Complex a, Complex b) {
    Complex diff = a;
    
    complexDecrement(&diff, b);
    return diff;
}

Complex complexProduct(Complex a, Complex b) {
    Complex prod = a;
    
    complexMultiply(&prod, b);
    return prod;
}

int complexEqual(Complex a, Complex b) {
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this) {
    return hypot(this.re, this.im);
}

void complexPrint(Complex this) {
    if ( this.im < 0 ) {
        printf("%g%gi", this.re, this.im);
    } else {
        printf("%g+%gi", this.re, this.im);
    }
}

int main() {
    Complex c1 = {1,2};
    Complex c2 = {3,4};

    complexPrint(c1);
    complexPrint(c2);
    printf("\n");
    complexIncrement(&c1,c2);
    complexPrint(c1);
    printf("\n");
    complexDecrement(&c1,c2);
    complexPrint(c1);
    printf("\n");
    complexMultiply(&c1,c2);
    complexPrint(c1);
    printf("\n");
    complexPrint(complexSum(c1,c2));
    printf("\n");
    complexPrint(complexDiff(c1,c2));
    printf("\n");
    complexPrint(complexProduct(c1,c2));

    return 0;
}