package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class Section extends Entity {
    public Section() {
        super();
    }

    public Section(Integer id) {
        super(id);
    }

    public String getTitle() {
        return (String) super.getColumn("title");
    }

    public void setTitle(String value) {
        super.setColumn("title", value);
    }

    public List<Category> getCategories() {
        return super.getChildren(Category.class);
    }

    public static List<Section> all() {
        return Entity.all(Section.class);
    }
}
