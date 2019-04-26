#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char model[10];
    int fuel;
    Point location;
} Car;

void move (Car *car, Point location) {
    Car->location.x = location.x;
    Car->location.y = location.y;
}

void refill (Car *car, int howManyFuel) {
    Car->fuel = howManyFuel;
}

void showCar (Car *car) {
    printf("Car model = %s;\n
            fuel quantity = %d;\n
            location = (%d, %d)", Car->model, Car->fuel, Car->location.x, Car->location.y);
}

void initCar (Car *car)
void main() {


    return 0;
}