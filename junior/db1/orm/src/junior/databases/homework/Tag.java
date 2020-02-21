package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class Tag extends Entity {
    public Tag() {
        super();
    }

    public Tag(Integer id) {
        super(id);
    }

    public String getName() {
        return (String) super.getColumn("name");
    }

    public void setName(String value) {
        super.setColumn("name", value);
    }

    public List<Post> getPosts() {
        return super.getSiblings(Post.class);
    }

    public static List<Tag> all() {
        return Entity.all(Tag.class);
    }
}
