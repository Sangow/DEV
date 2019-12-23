import java.lang.reflect.InvocationTargetException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Test {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException, SQLException {

        Class.forName("org.postgresql.Driver");

        try ( Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost/shop?user=shop&password=shop") ) {
               Statement st =  connection.createStatement();

            System.out.println(st.executeUpdate("CREATE TABLE \"test\" (test_id integer not null, test_name varchar(20) not null)"));

        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }

    }
}
