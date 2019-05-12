package Car;

public class Car {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point locaction;
    private String model;

    public Car() {
        this.fuelAmount = 0;
        this.fuelCapacity = 60;
        this.fuelConsumption = 0.6;
        this.locaction = new Point(0,0);
        this.model = "Mersedes";
    }

    public Car(double capacity, double consumption, Point location, String model) {
        this.fuelAmount = 0;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.locaction = location;
        this.model = model;
    }

    public double getFuelAmount() {
        return this.fuelAmount;
    }

    public double getFuelCapacity() {
        return this.fuelCapacity;
    }

    public double getFuelConsumption() {
        return this.fuelConsumption;
    }

    public Point getLocaction() {
        return this.locaction;
    }

    public String getModel() {
        return this.model;
    }

    public void drive(Point destination) throws OutOfFuel {
        double fuelNeeded = this.locaction.distance(destination) * this.fuelConsumption;

        if ( fuelNeeded > this.fuelAmount ) {
            throw new OutOfFuel();
        }
        this.fuelAmount -= fuelNeeded;
        this.locaction = destination;
    }

    public void drive(double x, double y) throws OutOfFuel {
        Point destination = new Point(x, y);
        this.drive(destination);
    }

    public void refill(double fuel) throws ToMuchFuel {
        if ( this.fuelAmount + fuel > this.fuelCapacity ) {
            throw new ToMuchFuel();
        }
        this.fuelAmount += fuel;
    }

    @Override
    public String toString() {
        return String.format("Model: " + this.getModel() + "\n"
                            + "Consumption: " + this.getFuelConsumption() +"\n"
                            + "Fuel: " + this.getFuelAmount() + "/" + this.getFuelCapacity() + "\n"
                            + "Location: " + this.getLocaction());
    }
}
