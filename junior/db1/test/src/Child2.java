import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Arrays;

public class Child2 extends Child {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
        } catch (ClassNotFoundException e) {
            System.err.println(e.getMessage());
        }
        try {
            Connection connection = DriverManager.getConnection(
                    "jdbc:postgresql://localhost/orm", "orm",
                    "orm");

            Statement st = connection.createStatement();
            st.addBatch("CREATE TABLE \"post__tag\" (\n" +
                    "    \"post_id\" INTEGER NOT NULL,\n" +
                    "    \"tag_id\" INTEGER NOT NULL,\n" +
                    "    PRIMARY KEY (\"post_id\", \"tag_id\")\n" +
                    ")");
            st.addBatch("CREATE TABLE \"post\" (\n" +
                    "    \"post_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"post_content\" text,\n" +
                    "    \"post_title\" varchar(255),\n" +
                    "    \"post_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"post_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("CREATE TABLE \"section\" (\n" +
                    "    \"section_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"section_title\" varchar(255),\n" +
                    "    \"section_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"section_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("CREATE TABLE \"user\" (\n" +
                    "    \"user_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"user_name\" varchar(255),\n" +
                    "    \"user_email\" varchar(255),\n" +
                    "    \"user_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"user_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("CREATE TABLE \"tag\" (\n" +
                    "    \"tag_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"tag_name\" varchar(255),\n" +
                    "    \"tag_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"tag_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("CREATE TABLE \"category\" (\n" +
                    "    \"category_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"category_title\" varchar,\n" +
                    "    \"category_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"category_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("CREATE TABLE \"comment\" (\n" +
                    "    \"comment_id\" SERIAL PRIMARY KEY,\n" +
                    "    \"comment_date\" integer,\n" +
                    "    \"comment_text\" varchar(255),\n" +
                    "    \"comment_author\" varchar(255),\n" +
                    "    \"comment_created\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER),\n" +
                    "    \"comment_updated\" INTEGER NOT NULL DEFAULT cast(extract(epoch from now()) AS INTEGER)\n" +
                    ")");
            st.addBatch("ALTER TABLE \"post__tag\"\n" +
                    "    ADD CONSTRAINT \"fk_post__tag_post_id\" FOREIGN KEY (\"post_id\") REFERENCES \"post\" (\"post_id\")");
            st.addBatch("ALTER TABLE \"post__tag\"\n" +
                    "    ADD CONSTRAINT \"fk_post__tag_tag_id\" FOREIGN KEY (\"tag_id\") REFERENCES \"tag\" (\"tag_id\")");
            st.addBatch("ALTER TABLE \"post\" ADD \"category_id\" INTEGER NOT NULL,\n" +
                    "    ADD CONSTRAINT \"fk_post_category_id\" FOREIGN KEY (\"category_id\") REFERENCES \"category\" (\"category_id\")");
            st.addBatch("ALTER TABLE \"comment\" ADD \"user_id\" INTEGER NOT NULL,\n" +
                    "    ADD CONSTRAINT \"fk_comment_user_id\" FOREIGN KEY (\"user_id\") REFERENCES \"user\" (\"user_id\")");
            st.addBatch("ALTER TABLE \"comment\" ADD \"post_id\" INTEGER NOT NULL,\n" +
                    "    ADD CONSTRAINT \"fk_comment_post_id\" FOREIGN KEY (\"post_id\") REFERENCES \"post\" (\"post_id\")");
            st.addBatch("ALTER TABLE \"category\" ADD \"section_id\" INTEGER NOT NULL,\n" +
                    "    ADD CONSTRAINT \"fk_category_section_id\" FOREIGN KEY (\"section_id\") REFERENCES \"section\" (\"section_id\")");
            st.addBatch("CREATE OR REPLACE FUNCTION update_section_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.section_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_section_updated\" BEFORE UPDATE ON \"section\" FOR EACH ROW EXECUTE PROCEDURE update_section_timestamp()");
            st.addBatch("CREATE OR REPLACE FUNCTION update_user_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.user_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_user_updated\" BEFORE UPDATE ON \"user\" FOR EACH ROW EXECUTE PROCEDURE update_user_timestamp()");
            st.addBatch("CREATE OR REPLACE FUNCTION update_category_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.category_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_category_updated\" BEFORE UPDATE ON \"category\" FOR EACH ROW EXECUTE PROCEDURE update_category_timestamp()");
            st.addBatch("CREATE OR REPLACE FUNCTION update_post_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.post_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_post_updated\" BEFORE UPDATE ON \"post\" FOR EACH ROW EXECUTE PROCEDURE update_post_timestamp()");
            st.addBatch("CREATE OR REPLACE FUNCTION update_tag_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.tag_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_tag_updated\" BEFORE UPDATE ON \"tag\" FOR EACH ROW EXECUTE PROCEDURE update_tag_timestamp()");
            st.addBatch("CREATE OR REPLACE FUNCTION update_comment_timestamp()\n" +
                    "RETURNS TRIGGER AS $$\n" +
                    "BEGIN\n" +
                    "   NEW.comment_updated = cast(extract(epoch from now()) as integer);\n" +
                    "   RETURN NEW;\n" +
                    "END;\n" +
                    "$$ language 'plpgsql'");
            st.addBatch("CREATE TRIGGER \"tr_comment_updated\" BEFORE UPDATE ON \"comment\" FOR EACH ROW EXECUTE PROCEDURE update_comment_timestamp()");

            System.out.println(Arrays.toString(st.executeBatch()));

        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
    }
}
