package Basic.Vector;

import java.util.ArrayList;

public class MainVector {
    public static void main(String[] args) {
        Vector v1 = new Vector(1,4);
        Vector v2 = new Vector(5, 10);

        System.out.println(v1.len());
        v1.sum(v2);

        System.out.println(v1.equal(v2));
        System.out.println(v1.notEqual(v2));

//        ArrayList

        System.out.println(v1);
    }
}
