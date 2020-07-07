import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class hashmap {
    Map<String, String> map = new HashMap<>();

    public static void main(String[] arg) {
        Map<String, String> map = new HashMap<>();
//        var map = new HashMap<>();

        map.put("Integer", "aa");
        map.put("Float", "bb");
        map.put("String", "cc");
        map.put("Boolean", "dd");
        map.put("Map", "aa");
        map.put("HashMap", "bb");
        map.put("TreeMap", "cc");
        map.put("LinkedHashMap", "dd");

        for (String s : map.keySet()) {
            System.out.println(s);
        }

        map.keySet().forEach(key -> System.out.println(key));
        map.values().forEach(value -> System.out.println(value));

        Set<Map.Entry<String, String>> entries = map.entrySet();

        for (Map.Entry<String, String> entry : entries) {
            System.out.print("key: " + entry.getKey());
            System.out.println(", Value: " + entry.getValue());
        }

        // or (lambda expression)
//        map.forEach((key, value) -> {
//            System.out.print("key: " + key);
//            System.out.println(", Value: " + value);
//        });

        map.computeIfAbsent("Flo", k -> {
            System.out.print("key: " + k);
            return "new";
        });
    }
}
