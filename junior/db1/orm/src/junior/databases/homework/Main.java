package junior.databases.homework;

import junior.databases.homework.*;
import java.sql.*;

public class Main {
    private static Connection connection = null;

    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        initDatabase();

        Entity.setDatabase(connection);


        for ( Post post : Post.all() ) {
            System.out.println(post.getId() + ": " + post.getTitle());

            for ( Tag tag : post.getTags() ) {
                System.out.println("  " + tag.getName());

                for ( Post p : tag.getPosts() ) {
                    System.out.println("    " + p.getId() + ": " + p.getTitle());
                }
            }
        }
    }

    private static void initDatabase() throws SQLException, ClassNotFoundException {
        Class.forName("org.postgresql.Driver");

        connection = DriverManager.getConnection(
                    "jdbc:postgresql://<host>/<name>", "<user>",
                    "<password>");
    }
}
