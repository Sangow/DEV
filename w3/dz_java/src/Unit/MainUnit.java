package Unit;

public class MainUnit {
    public static void main(String[] args) {
        Unit barbarian = new Unit("Barbarian", 200, 181);
        Unit knight = new Unit("Knight", 180, 25);

        try {
            System.out.println(barbarian);
            System.out.println(knight);

            barbarian.attack(knight);

            System.out.println(barbarian);
            System.out.println(knight);

            knight.addHitPoints(200);

            System.out.println(barbarian);
            System.out.println(knight);

        } catch (UnitIsDead e) {
            System.out.println("**********Unit is dead**********");
            System.out.println(barbarian);
            System.out.println(knight);
        }
    }
}