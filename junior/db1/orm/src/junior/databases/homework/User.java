package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class User extends Entity {
    public User() {
        super();
    }

    public User(Integer id) {
        super(id);
    }

    public Integer getAge() {
        return (Integer) super.getColumn("age");
    }

    public String getName() {
        return (String) super.getColumn("name");
    }

    public String getEmail() {
        return (String) super.getColumn("email");
    }

    public void setAge(Integer value) {
        super.setColumn("age", value);
    }

    public void setName(String value) {
        super.setColumn("name", value);
    }

    public void setEmail(String value) {
        super.setColumn("email", value);
    }

    public List<Comment> getComments() {
        return super.getChildren(Comment.class);
    }

    public static List<User> all() {
        return Entity.all(User.class);
    }
}
