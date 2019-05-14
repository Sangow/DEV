public class Unit {
    private int damage;
    private int hitPoints;
    private int hitPointsLimit;
    private String name;

    private void ensureIsAlive() throws UnitIsDead {
        if ( this.hitPoints == 0 ) {
            throw new UnitIsDead();
        }
    }

    public Unit(String name, int hp, int dmg) {
        this.damage = dmg;
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.name = name;
    }

    public int getDamage() {
        return damage;
    }

    public int getHitPoints() {
        return hitPoints;
    }

    public int getHitPointsLimit() {
        return hitPointsLimit;
    }

    public String getName() {
        return name;
    }

    public void addHitPoints(int hp) throws UnitIsDead {
        this.ensureIsAlive();

        System.out.println(this.name + " restored heath!\n");

        if ( hp > this.hitPointsLimit - this.hitPoints ) {
            this.hitPoints = this.hitPointsLimit;
            return;
        }
        this.hitPoints += hp;
    }

    public void takeDamage(int dmg) throws UnitIsDead {
        this.ensureIsAlive();

        if ( dmg > this.hitPoints ) {
            this.hitPoints = 0;
            return;
        }
        this.hitPoints -= dmg;
    }

    public void attack(Unit enemy) throws UnitIsDead {
        enemy.takeDamage(this.damage);
        System.out.println(this.name + " attacked " + enemy.name + "\n");

        enemy.ensureIsAlive();

        enemy.counterAttack(this);
    }

    public void counterAttack(Unit enemy) throws UnitIsDead {
        enemy.takeDamage(this.damage / 2);
        System.out.println(this.name + " counterattacked " + enemy.name + "\n");
    }

    public String toString() {
        if ( this.getHitPoints() == 0 ) {
            return  String.format(this.getName() + " is dead!");
        }
        return String.format("Unit: " + this.getName() + "\n"
                            + "Health: " + this.getHitPoints() + "/" + this.getHitPointsLimit() + "HP\n"
                            + "Damage: " + this.getDamage() + "dmg\n");
    }
}
