public class RemoveString {
    public static void main(String[] args) {
        int result = 0;
        String s = "aabcbcd";
        String t = "abc";

        while (s.contains(t)) {
            result++;
            s = s.replaceFirst(t, "");
        }

        System.out.println("result : "+ result);
    }
}
