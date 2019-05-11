import java.util.Scanner;

public class IsPali {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); //создаем сканнер
        String input = in.nextLine(); // считываем строку
        StringBuffer reversed = new StringBuffer(input); // делаем копию

        reversed.reverse(); // делаем реверс строки

        //сравниваем и выводим результат
        if ( input.equals(reversed.toString()) ) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }

        in.close();
    }
}