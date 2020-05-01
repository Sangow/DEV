package foo;

import java.util.List;
import java.util.ArrayList;

public class HobbyStorage {
    public List getHobbyNames(String hobby) {
        List hobbyNames = new ArrayList();

        if ( hobby.equals("extreme knitting") ) {
            hobbyNames.add("Fred");
            hobbyNames.add("Pradeep");
            hobbyNames.add("Philippe");
        } else {
            hobbyNames.add("Sergey");
            hobbyNames.add("Max");
            hobbyNames.add("Nastya");
        }

        return(hobbyNames);
    }
}