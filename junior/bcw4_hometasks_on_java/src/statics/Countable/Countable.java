package statics.Countable;

public class Countable {
    private static int instanceCount = 0;

    public Countable() {
        instanceCount += 1;
    }

    public static int getInstanceCount() {
        return instanceCount;
    }
}