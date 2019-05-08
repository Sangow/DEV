#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::~Vector() {}

double Vector::getX() const {
    return this->x;
}

double Vector::getY() const {
    return this->y;
}

void Vector::setX(double x) {
    this->x = x;
}

void Vector::setY(double y) {
    this->y = y;
}

double Vector::len() const {
    return hypot(this->x, this->y);
}

bool Vector::operator==(const Vector& other) const {
    return this->x == other.x && this->y == other.y;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

void Vector::operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
}

void Vector::operator-=(const Vector& other) {
    this->x -= other.x;
    this->y -= other.y;
}

Vector Vector::operator+(const Vector& other) const {
    Vector result = *this;

    result += other;
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    Vector result = *this;

    result -= other;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    return out << "(" << vector.getX() << ", " << vector.getY() << ")";
}