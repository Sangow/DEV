package Car;

public class MainCar {
    public static void main(String[] args) throws OutOfFuel, ToMuchFuel {
        Car car = new Car();

        System.out.println(car);

        car.refill(50);

        System.out.println("Fuel amount: " + car.getFuelAmount());

        car.drive(new Point(5, 11));

        System.out.println(car);

        car.drive(10, 20);

        System.out.println(car);

//        car.refill(50);
    }
}
