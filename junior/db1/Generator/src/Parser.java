import org.yaml.snakeyaml.Yaml;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Map;
import java.util.StringJoiner;

class YamlReader {

    public Map<String, Map<String, Map<String, String>>> read(String path) throws IOException {
        InputStream in = Files.newInputStream(Paths.get(path));
        Yaml yaml = new Yaml();
        return (Map<String, Map<String, Map<String, String>>>) yaml.load(in);
    }
}

public class Parser {
    public static void main(String[] args) throws IOException {
        ArrayList<String> statements = new ArrayList<>();
        YamlReader reader = new YamlReader();

        Map<String, Map<String, Map<String, String>>> config = reader.read("db.yml");

        for( Map.Entry<String, Map<String, Map<String, String>>> entry0 : reader.read("db.yml").entrySet() ) {
            for ( Map.Entry<String, Map<String, String>> entry1 : entry0.getValue().entrySet() ) {
                StringJoiner sj = new StringJoiner(", ", "", "");

                sj.add("\n\t" + entry0.getKey() + "_id");

                for ( Map.Entry<String, String> entry2 : entry1.getValue().entrySet() ) {
                    sj.add("\n\t" + entry2.getKey() + " " + entry2.getValue());
                }

                statements.add("CREATE TABLE \"" + entry0.getKey() + "\" (" + sj + "\n);");
            }

        }

        for ( String s : statements ) {
            System.out.println(s);
        }

    }
}
