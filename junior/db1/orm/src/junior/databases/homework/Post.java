package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class Post extends Entity {
    public Post() {
        super();
    }

    public Post(Integer id) {
        super(id);
    }

    public String getTitle() {
        return (String) super.getColumn("title");
    }

    public String getContent() {
        return (String) super.getColumn("content");
    }

    public Category getCategory() {
        return super.getParent(Category.class);
    }

    public void setTitle(String value) {
        super.setColumn("title", value);
    }

    public void setContent(String value) {
        super.setColumn("content", value);
    }

    public void setCategory(Integer value) {
        super.setParent("category", value);
    }

    public void setCategory(Entity value) {
        super.setParent("category", value.getId());
    }

    public List<Tag> getTags() {
        return super.getSiblings(Tag.class);
    }

    public List<Comment> getComments() {
        return super.getChildren(Comment.class);
    }

    public static List<Post> all() {
        return Entity.all(Post.class);
    }
}
