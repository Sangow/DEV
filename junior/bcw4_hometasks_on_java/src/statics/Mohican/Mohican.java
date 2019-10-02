package statics.Mohican;

import javax.lang.model.element.NestingKind;

public class Mohican {
    private static Mohican lastMohican;
    private static int uniqueIDCount = 0;
    private String mName;
    private int mID;

    public Mohican(String mName) {
        this.mID = uniqueIDCount += 1;
        this.mName = mName;
        lastMohican = this;
    }

    public static Mohican getLastMohican() {
        return lastMohican;
    }

    @Override
    public String toString() {
        return String.format("Name: " + this.mName + " id: " + this.mID);
    }
}
