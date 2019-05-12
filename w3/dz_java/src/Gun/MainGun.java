package Gun;

public class MainGun {
    public static void main(String[] args) {
        Gun gun = new Gun();

        System.out.println(gun);

        gun.prepare();
        gun.reload();
        try {
            gun.shoot();
            gun.shoot();
            gun.shoot();
            gun.shoot();
            gun.shoot();
            gun.shoot();

            System.out.println(gun);
        } catch (OutOfRounds e) {
            System.out.println("Out of Rounds!");
        } catch (NotReady e) {
            System.out.println("Gun not ready!");
        }
    }
}
