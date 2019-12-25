package junior.databases.homework;

import junior.databases.homework.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

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


//        for ( Post post : Post.all() ) {
//            System.out.println(post.getId() + ": " + post.getTitle());
//
//            for ( Tag tag : post.getTags() ) {
//                System.out.println("  " + tag.getName());
//
//                for ( Post p : tag.getPosts() ) {
//                    System.out.println("    " + p.getId() + ": " + p.getTitle());
//                }
//            }
//        }
        Section s = new Section(1);
        System.out.println(s.getTitle());
        System.out.println(s.getTitle());
//        System.out.println(s.getId());
//        System.out.println(s.getCreated());
//        System.out.println(s.getUpdated());
    }

    private static void initDatabase() throws SQLException, ClassNotFoundException {
        Class.forName("org.postgresql.Driver");

        connection = DriverManager.getConnection(
                    "jdbc:postgresql://localhost/orm", "orm",
                    "orm");
    }
}
