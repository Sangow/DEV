#include <iostream>
#include "Complex.h"

Complex::Complex(double real=0, double imaginary=0) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex() {}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImaginary() const {
    return this->imaginary;
}

bool Complex::operator==(const Complex& other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    Complex result = *this;

    result.real += other.real;
    result.imaginary += other.imaginary;
    return result;
}

Complex Complex::operator-(const Complex& other) const {
    Complex result = *this;

    result.real -= other.real;
    result.imaginary -= other.imaginary;
    return result;
}

Complex Complex::operator*(const Complex& other) const {
    Complex result = *this;

    result.real = this->real * other.real;
    result.imaginary = this->imaginary * other.imaginary;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.getImaginary() < 0) {
        return out << complex.getReal() << complex.getImaginary() << "i";
    } else {
        return out << complex.getReal() << "+" << complex.getImaginary();
    }
}

