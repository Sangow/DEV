#ifndef CAR_H
#define CAR_H

class Car {
    private:
        double maxFuel;
        double currentFuel;
        double consuption;
        char* model;

    public:
        Car();
        ~Car();

        double getMaxFuel() const;
        double getCurrentFuel() const;
        double getConsumption() const;

        void setMaxFuel(double maxFuel);
        void setCurrentFuel(double currentFuel);
        void setConsumption(double consuption);
};

#endif // CAR_H