package Gun;

public class Gun {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;

    public Gun() {
        this.amount = 0;
        this.capacity = 8;
        this.isReady = false;
        this.model = "Beretta";
        this.totalShots = 0;
    }

    public Gun(String model, int capacity) {
        this.amount = 0;
        this.capacity = capacity;
        this.isReady = false;
        this.model = model;
        this.totalShots = 0;
    }

    public int getAmount() {
        return amount;
    }

    public int getCapacity() {
        return capacity;
    }

    public boolean ready() {
        return isReady;
    }

    public String getModel() {
        return model;
    }

    public int getTotalShots() {
        return totalShots;
    }

    public void prepare() {
        if ( !this.isReady ) {
            this.isReady = true;
        }
    }

    public void reload() {
        this.amount = this.capacity;
        System.out.println("Gun reloaded!");
    }

    public void shoot() throws NotReady, OutOfRounds {
        if ( !this.isReady ) {
            throw new NotReady();
        }

        if ( this.amount == 0 ) {
            throw new OutOfRounds();
        }

        System.out.println("Bang!");
        this.amount -= 1;
        this.totalShots += 1;
    }

    public String toString() {
        return String.format("Gun model: " + this.getModel() + "\n"
                            + "Rounds/Capacity: " + this.getAmount() + "/" + this.getCapacity() + "\n"
                            + "Total shots: " + this.getTotalShots() + "\n"
                            + "Ready gun: " + this.ready());
    }
}