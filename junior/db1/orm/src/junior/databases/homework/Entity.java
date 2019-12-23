package junior.databases.homework;

import java.util.*;
import java.sql.*;
import java.lang.reflect.Constructor;

public abstract class Entity {
    private static String DELETE_QUERY   = "DELETE FROM \"%1$s\" WHERE %1$s_id=?";
    private static String INSERT_QUERY   = "INSERT INTO \"%1$s\" (%2$s) VALUES (%3$s) RETURNING %1$s_id";
    private static String LIST_QUERY     = "SELECT * FROM \"%s\"";
    private static String SELECT_QUERY   = "SELECT * FROM \"%1$s\" WHERE %1$s_id=?";
    private static String CHILDREN_QUERY = "SELECT * FROM \"%1$s\" WHERE %2$s_id=?";
    private static String SIBLINGS_QUERY = "SELECT * FROM \"%1$s\" NATURAL JOIN \"%2$s\" WHERE %3$s_id=?";
    private static String UPDATE_QUERY   = "UPDATE \"%1$s\" SET %2$s WHERE %1$s_id=?";

    private static Connection db = null;

    protected boolean isLoaded = false;
    protected boolean isModified = false;
    private String table = null;
    private int id = 0;
    protected Map<String, Object> fields = new HashMap<String, Object>();


    public Entity() {

    }

    public Entity(Integer id) {
        if ( db == null ) {
            throw new NullPointerException();
        }
        this.id = id;
        this.table = this.getClass().getSimpleName();

        try {
//            ResultSet resultSet = db.createStatement().executeQuery(String.format(SELECT_QUERY, this.table));
            PreparedStatement ps =  db.prepareStatement(String.format(SELECT_QUERY, this.table));
            ps.setInt(1, this.id);
            ps.executeQuery();

        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static final void setDatabase(Connection connection) {
        if ( connection == null ) {
            throw new NullPointerException();
        }
        db = connection;
        // throws NullPointerException
    }

    public final int getId() {
        // try to guess youtself
        return 0;
    }

    public final java.util.Date getCreated() {
        // try to guess youtself
    }

    public final java.util.Date getUpdated() {
        // try to guess youtself
    }

    public final Object getColumn(String name) {
        // return column name from fields by key
    }

    public final <T extends Entity> T getParent(Class<T> cls) {
        // get parent id from fields as <classname>_id, create and return an instance of class T with that id
    }

    public final <T extends Entity> List<T> getChildren(Class<T> cls) {
        // select needed rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // return list of children instances
    }

    public final <T extends Entity> List<T> getSiblings(Class<T> cls) {
        // select needed rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // return list of sibling instances
    }

    public final void setColumn(String name, Object value) {
        // put a value into fields with <table>_<name> as a key
    }

    public final void setParent(String name, Integer id) {
        // put parent id into fields with <name>_<id> as a key
    }

    private void load() {
        // check, if current object is already loaded
        // get a single row from corresponding table by id
        // store columns as object fields with unchanged column names as keys
    }

    private void insert() throws SQLException {
        // execute an insert query, built from fields keys and values
    }

    private void update() throws SQLException {
        // execute an update query, built from fields keys and values
    }

    public final void delete() throws SQLException {
        // execute a delete query with current instance id
    }

    public final void save() throws SQLException {
        // execute either insert or update query, depending on instance id
    }

    protected static <T extends Entity> List<T> all(Class<T> cls) {
        // select ALL rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // aggregate all new instances into a single List<T> and return it
    }

    private static Collection<String> genPlaceholders(int size) {
        // return a collection, consisting of <size> "?" symbols,
        // which should be joined later.
        // each "?" is used in insert statements as a placeholder for values (google prepared statements)
    }

    private static Collection<String> genPlaceholders(int size, String placeholder) {
        // return a collection, consisting of <size> <placeholder> symbols,
        // which should be joined later.
        // each <placeholder> is used in insert statements as a placeholder for values (google prepared statements)
    }

    private static String getJoinTableName(String leftTable, String rightTable) {
        // generate the name of associative table for many-to-many relation
        // sort left and right tables alphabetically
        // return table name using format <table>__<table>
    }

    private java.util.Date getDate(String column) {
        // pwoerful method, used to remove copypaste from getCreated and getUpdated methods
    }

    private static String join(Collection<String> sequence) {
        // join collection of strings with ", " as <glue> and return a joined string
    }

    private static String join(Collection<String> sequence, String glue) {
        // join collection of strings with <glue> and return a joined string
    }

    private static <T extends Entity> List<T> rowsToEntities(Class<T> cls, ResultSet rows) {
        // convert a ResultSet of database rows to list of instances of corresponding class
        // each instance must be filled with its data so that it must not produce additional queries to database to get it's fields
    }
}
