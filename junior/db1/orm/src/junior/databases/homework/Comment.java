package junior.databases.homework;

import java.util.List;
import java.sql.SQLException;

class Comment extends Entity {
    public Comment() {
        super();
    }

    public Comment(Integer id) {
        super(id);
    }

    public String getText() {
        return (String) super.getColumn("text");
    }

    public void setText(String value) {
        super.setColumn("text", value);
    }

    public Post getPost() {
        return super.getParent(Post.class);
    }

    public void setPost(Integer id) {
        super.setParent("post", id);
    }

    public void setPost(Post post) {
        super.setParent("post", post.getId());
    }

    public User getUser() {
        return super.getParent(User.class);
    }

    public void setUser(Integer id) {
        super.setParent("user", id);
    }

    public void setUser(User user) {
        super.setParent("user", user.getId());
    }

    public static List<Comment> all() {
        return Entity.all(Comment.class);
    }
}
