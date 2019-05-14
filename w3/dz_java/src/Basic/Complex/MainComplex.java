public class MainComplex {
    public static void main(String[] args) {
        Complex comp1 = new Complex();
        Complex comp2 = new Complex(5, 10);

        System.out.println(comp1.equal(comp2));

        comp1.addition(comp2);
        System.out.println(comp1);

        comp1.multiple(comp2);
        System.out.println(comp1);
    }
}
