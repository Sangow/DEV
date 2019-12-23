
import java.lang.reflect.InvocationTargetException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Arrays;

class Test {

    public String getClassN() {
        return this.getClass().getSimpleName().toLowerCase();
    }
}

