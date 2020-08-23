import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class regex {
    static public void main(String[] args) {
        // Pattern
//        String REGEX = "([0-9]{2,3}-[0-9]{3,4}-[0-9]{4})";
//        String INPUT = "here is my number, 010-1234-5678. touch me.";
//        String INPUT1 = "010-1234-5678";

//        Pattern pattern = Pattern.compile(REGEX);
//        Matcher matcher = pattern.matcher(INPUT);
//        System.out.println(pattern.matches(REGEX, INPUT));
//        "[123".matches("[123");
//
//// wrapping the bracket in \Q and \E allows the pattern to match as you would expect
//        System.out.println("[123".matches("\\Q[\\E123"));
//        System.out.println("[123".matches(Pattern.quote("[123")));
//
//        String REGEX = ":";
//        String INPUT = "boo:and:foo::";
//
//        Pattern pattern = Pattern.compile(REGEX);
//        System.out.println(pattern.toString());


        // Matcher
//        String REGEX = "(a*b)";
//        String INPUT = "aabfooabfooaabfoo";
//        String REPLACE = "-";
//        Pattern pattern = Pattern.compile(REGEX);
//
//
//        Matcher matcher = pattern.matcher(INPUT);
//        StringBuffer buffer = new StringBuffer();
//
//        while (matcher.find()) {
//            System.out.println(matcher.group(2));
//        }
//        System.out.println(buffer.toString());
//        matcher.appendTail(buffer);
//        System.out.println(buffer.toString());


        // Matcher - start, end
        String REGEX = "a*b";
        String INPUT = "aabfooabfooaabfoo";
        Pattern pattern = Pattern.compile(REGEX);

        Matcher matcher = pattern.matcher(INPUT);
        while (matcher.find()) {
            System.out.println(matcher.start());
        }
//
        while (matcher.find()) {
            System.out.println(matcher.end());
        }
    }
}