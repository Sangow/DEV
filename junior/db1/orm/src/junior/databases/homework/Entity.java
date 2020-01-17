package junior.databases.homework;

import java.util.*;
import java.sql.*;

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
        this.table = this.getClass().getSimpleName().toLowerCase();
    }

    public static final void setDatabase(Connection connection) {
        // throws NullPointerException
        if ( connection == null ) {
            throw new NullPointerException();
        }
        db = connection;
    }

    public final Object getColumn(String name) {
        // return column name from fields by key
        if ( this.isModified ) {
            System.err.println("Modified!");
        }
        if ( !this.isLoaded ) {
            this.load();
        }
        return this.fields.get(String.format("%s_%s", this.table, name));
    }

    public final int getId() {
//        return this.id;
        return (int)this.getColumn("id");
    }

    private java.util.Date getDate(String column) {
        // pwoerful method, used to remove copypaste from getCreated and getUpdated methods
        return new java.util.Date((int)this.getColumn(column));
    }

    public final java.util.Date getCreated() {
        // try to guess youtself
        return this.getDate("created");
    }

    public final java.util.Date getUpdated() {
        // try to guess youtself
        return this.getDate("updated");
    }

    public final <T extends Entity> T getParent(Class<T> cls) {
        // get parent id from fields as <classname>_id, create and return an instance of class T with that id
        return null;
    }

    public final <T extends Entity> List<T> getChildren(Class<T> cls) {
        // select needed rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // return list of children instances
        return null;
    }

    public final <T extends Entity> List<T> getSiblings(Class<T> cls) {
        // select needed rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // return list of sibling instances
        return null;
    }

    public final void setColumn(String name, Object value) {
        // put a value into fields with <table>_<name> as a key
//        if ( this.fields.containsKey(String.format("%s_%s", this.table, name)) ) {
            this.fields.put(String.format("%s_%s", this.table, name), value);
            this.isModified = true;
//            return;
//        }
//        System.err.println("Field does not exist!");
    }

    public final void setParent(String name, Integer id) {
        // put parent id into fields with <name>_<id> as a key
    }

    private void load() {
        // check, if current object is already loaded
        // get a single row from corresponding table by id
        // store columns as object fields with unchanged column names as keys
        try {
            PreparedStatement ps =  db.prepareStatement(String.format(SELECT_QUERY, this.table));
            ps.setInt(1, this.id);

            ResultSet rs =  ps.executeQuery();
            ResultSetMetaData rsmd = rs.getMetaData();

            rs.next();

            for ( int i = 1; i <= rsmd.getColumnCount(); i++ ) {
                fields.put(rsmd.getColumnName(i), rs.getObject(i));
            }
        } catch (SQLException se) {
            System.err.println(se.getMessage());
        }

        this.isLoaded = true;
    }

    private void insert() throws SQLException {
        // execute an insert query, built from fields keys and values
        this.isModified = false;
    }

    private void update() throws SQLException {
        // execute an update query, built from fields keys and values
        ArrayList<String> seq = new ArrayList<>();

        for ( Map.Entry<String, Object> e : this.fields.entrySet() ) {
            seq.add(String.format("%s = %s", e.getKey(), e.getValue().toString()));
        }

        PreparedStatement ps = db.prepareStatement(String.format(UPDATE_QUERY, this.table, Entity.join(seq)));

        ps.setInt(1, this.id);
        ps.executeUpdate();

        this.isModified = false;
    }

    public final void delete() throws SQLException {
        // execute a delete query with current instance id
    }

    public final void save() throws SQLException {
        // execute either insert or update query, depending on instance id
        if ( this.id == 0 ) {
            this.insert();
        } else {
            this.update();
        }
    }

    protected static <T extends Entity> List<T> all(Class<T> cls) {
        // select ALL rows and ALL columns from corresponding table
        // convert each row from ResultSet to instance of class T with appropriate id
        // fill each of new instances with column data
        // aggregate all new instances into a single List<T> and return it
        return null;
    }

    private static Collection<String> genPlaceholders(int size) {
        // return a collection, consisting of <size> "?" symbols,
        // which should be joined later.
        // each "?" is used in insert statements as a placeholder for values (google prepared statements)
        return null;
    }

    private static Collection<String> genPlaceholders(int size, String placeholder) {
        // return a collection, consisting of <size> <placeholder> symbols,
        // which should be joined later.
        // each <placeholder> is used in insert statements as a placeholder for values (google prepared statements)
        return null;
    }

    private static String getJoinTableName(String leftTable, String rightTable) {
        // generate the name of associative table for many-to-many relation
        // sort left and right tables alphabetically
        // return table name using format <table>__<table>
        return null;
    }

    private static String join(Collection<String> sequence) {
        // join collection of strings with ", " as <glue> and return a joined string
         return Entity.join(sequence, ", ");
    }

    private static String join(Collection<String> sequence, String glue) {
        // join collection of strings with <glue> and return a joined string
        StringJoiner sj = new StringJoiner(glue);

        for ( String part : sequence ) {
            sj.add(part);
        }

        return sj.toString();
    }

    private static <T extends Entity> List<T> rowsToEntities(Class<T> cls, ResultSet rows) {
        // convert a ResultSet of database rows to list of instances of corresponding class
        // each instance must be filled with its data so that it must not produce additional queries to database to get it's fields
        return null;
    }
}
