#include <stdio.h>

typedef struct {
    char model[10];
    int fuel;
    int position;
} Car;

void refillCar (Car *car, int howManyFuel) {
    car->fuel = howManyFuel;
}

void showCar (Car *car) {
    printf("Car model = %s;\nfuel quantity = %d;\nposition = %d\n", car->model, car->fuel, car->position);
}

void initCar (Car *car) {
    scanf("%9s %d %d", car->model, &(car->fuel), &(car->position));
}

int isDTP(Car car1, Car car2){
    return car1.position == car2.position;
}

void moveCar (Car *car, int newPosition) {
    if ( car->fuel <= 0 ) {
        refillCar(*(&car), 100);
    }
    car->position = newPosition;
    car->fuel -= newPosition * 2;
}

void main() {
    Car bmw;
    Car mers;

    initCar(&bmw);
    showCar(&bmw);

    initCar(&mers);
    showCar(&mers);

    moveCar(&bmw, 10);
    moveCar(&mers, 15);

    showCar(&bmw);
    showCar(&mers);

}