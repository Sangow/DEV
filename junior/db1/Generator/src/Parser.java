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

    private String timestamp(String tableName) {
        return String.format("%1$s_created timestamp not null default now()," +
                             "\n\t%1$s_updated timestamp not null default now()",
                                                                                tableName);
    }

    private String createFunction(String tableName) {
        return String.format("CREATE FUNCTION %1$s_trigger_set_timestamp()" +
                             "\nRETURNS TRIGGER AS $$" +
                             "\nBEGIN" +
                                 "\n\tNEW.%1$s_updated = NOW();" +
                                 "\n\tRETURN NEW;" +
                             "\nEND;" +
                             "\n$$ LANGUAGE plpgsql;",
                                                        tableName);
    }

    private String createTrigger(String tableName){
        return String.format("CREATE TRIGGER %1$s_timestamp_changed" +
                             "\nBEFORE UPDATE ON %1$s" +
                             "\nFOR EACH ROW" +
                             "\nEXECUTE PROCEDURE %1$s_trigger_set_timestamp();",
                                                                            tableName);
    }

    private void parsePair(Map<String, String> pair, StringJoiner sj, String tableName) {
        for ( Map.Entry<String, String> p : pair.entrySet() ) {
            sj.add(String.format("\n\t%s_%s %s not null", tableName, p.getKey(), p.getValue()));
        }
    }

    private void parseCondition(Map<String, Map<String, String>> condition, StringJoiner sj, String tableName) {
        for ( Map.Entry<String, Map<String, String>> c : condition.entrySet() ) {
             sj.add(String.format("\n\t%s_id integer not null", tableName));

             this.parsePair(c.getValue(), sj, tableName);

            sj.add("\n\t" + this.timestamp(tableName));
            sj.add(String.format("\n\tPRIMARY KEY (%s_id)", tableName));
        }
    }

    private void concatParsed(String tableName, StringJoiner sj) {
        this.statements.add(String.format("CREATE TABLE \"%s\" (%s\n);", tableName, sj));
        this.statements.add(createFunction(tableName));
        this.statements.add(createTrigger(tableName));
    }

    public Parser(String path) {
        this.statements = new ArrayList<>();
        this.reader = new YamlReader();
        this.path = path;
    }

    public ArrayList<String> parse() throws IOException {
        for( Map.Entry<String, Map<String, Map<String, String>>> table : reader.read(this.path).entrySet() ) {
            StringJoiner sj = new StringJoiner(",", "", "");

            this.parseCondition(table.getValue(), sj, table.getKey());

            this.concatParsed(table.getKey(), sj);
        }
        return this.statements;
    }

    public static void main(String[] args) throws IOException {
        if ( args.length == 0 ) {
            System.err.println("INPUT Yaml file path.");
            return;
        }

        for ( String s : new Parser(args[0]).parse() ) {
            System.out.println(s + "\n");
        }
    }
}
