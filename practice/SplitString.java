import java.util.ArrayList;

public class SplitString {

    public static String[] solution(String s) {
            ArrayList answer = new ArrayList();
            int ai =0;

            int i=0, b=s.length()-1;
            String front="", back="";

            while (i <= b) {
                front += s.charAt(i++);
                back = s.charAt(b--) + back;

                if (front.equals(back)) {
                    answer.add(ai++, front);
                    answer.add(answer.size()-ai, back);
                    front = back = "";
                }
            }
            if (front != "" || back != "")
                answer.add(ai++, front+back);

            return (String[]) answer.toArray(new String[answer.size()]);
    }

    public static void main(String[] args) {
        String testString1 = "abcxyasdfasdfxyabc";
        String testString2 = "abcabcabcabc";
        String testString3 = "zzzzzz";
        String testString4 = "llttaattll";
        String testString5 = "abcdef";
        String s = testString3;

        String[] answer = solution(s);

        System.out.println("answer : " + answer);
    }
}
