package statics.Identifiable;

import statics.Countable.Countable;

import java.io.StringReader;

public class Identifiable {
    private static int instanceCount = 0;
    private int uniqueID;
    private String name;

    public Identifiable() {
        instanceCount += 1;
        this.uniqueID = instanceCount;
        this.name = "Name" + this.uniqueID;
    }

    public static int getInstanceCount() {
        return instanceCount;
    }

    @Override
    public String toString() {
        return String.format("Name / id: " + this.name + " " + this.uniqueID);
    }
}
