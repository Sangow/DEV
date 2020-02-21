package junior.databases.homework;

import junior.databases.homework.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;

public class Main {
    private static Connection connection = null;

    public static void main(String[] args) {
        try {
            initDatabase();
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            System.err.println(e.getMessage());;
        }

        Entity.setDatabase(connection);

        List<User> allUsers = User.all();

        for ( User u : allUsers ) {
            System.out.println(u.getName());
        }
    }

    private static void initDatabase() throws SQLException, ClassNotFoundException {
        Class.forName("org.postgresql.Driver");

        connection = DriverManager.getConnection(
                    "jdbc:postgresql://localhost/shop", "shop",
                    "shop");
    }
}
