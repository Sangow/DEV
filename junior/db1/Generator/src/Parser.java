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
    private ArrayList<String> statements;
    private YamlReader reader;
    private String path;

    public Parser(String path) {
        this.statements = new ArrayList<>();
        this.reader = new YamlReader();
        this.path = path;
    }

    public ArrayList<String> parse() throws IOException {
        for( Map.Entry<String, Map<String, Map<String, String>>> entry0 : reader.read(this.path).entrySet() ) {
            for ( Map.Entry<String, Map<String, String>> entry1 : entry0.getValue().entrySet() ) {
                StringJoiner sj = new StringJoiner(", ", "", "");

                sj.add(String.format("\n\t%s_id", entry0.getKey()));

                for ( Map.Entry<String, String> entry2 : entry1.getValue().entrySet() ) {
                    sj.add(String.format("\n\t%s_%s %s", entry0.getKey(), entry2.getKey(), entry2.getValue()));
                }

                this.statements.add(String.format("CREATE TABLE \"%s\" (%s\n);", entry0.getKey(), sj));
            }

        }
        return statements;
    }

    public static void main(String[] args) throws IOException {
        if ( args.length == 0 ) {
            System.err.println("INPUT Yaml file path.");
            return;
        }

        for ( String s : new Parser(args[0]).parse() ) {
            System.out.println(s);
        }
    }
}
