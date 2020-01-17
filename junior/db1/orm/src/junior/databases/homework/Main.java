package junior.databases.homework;

import junior.databases.homework.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

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
        User u = new User(1);
        u.setName("'Konwwww'");
        u.setEmail("'Very interesting'");
        try {
            u.save();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
//        Section s = new Section(1);
////        s.setTitle("newZalupa");
//        s.setTitle("zhopa");
//        try {
//            s.save();
//        } catch (SQLException e) {
//            System.err.println(e.getMessage());
//            System.err.println(e.getNextException().getMessage());
//        }
//        System.out.println(s.getId());
//        System.out.println(s.getCreated());
//        System.out.println(s.getUpdated());
//        try {
//            Statement st = connection.createStatement();
//            st.execute("UPDATE \"section\" SET section_title = \'sec\' WHERE section_id=1");
//        } catch (SQLException e) {
//            System.err.println(e.getMessage());
//        }
    }

    private static void initDatabase() throws SQLException, ClassNotFoundException {
        Class.forName("org.postgresql.Driver");

        connection = DriverManager.getConnection(
                    "jdbc:postgresql://localhost/shop", "shop",
                    "shop");
    }
}
