package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class Category extends Entity {
    public Category() {
        super();
    }

    public Category(Integer id) {
        super(id);
    }

    public String getTitle() {
        return (String) super.getColumn("title");
    }

    public void setTitle(String value) {
        super.setColumn("title", value);
    }

    public Section getSection() {
        return super.getParent(Section.class);
    }

    public void setSection(Integer id) {
        super.setParent("section", id);
    }

    public void setSection(Section section) {
        super.setParent("section", section.getId());
    }

    public List<Post> getPosts() {
        return super.getChildren(Post.class);
    }

    public static List<Category> all() {
        return Entity.all(Category.class);
    }
}
