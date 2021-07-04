public class Calculation {

    public static int n;
    public static int calculate(String n, int aim) {

        String build = "";
        for (int i = 0; i < n.length(); i++) {
            build += n.charAt(i);

        }

        return -1;
    }

    public static void main(String[] args) {
        int n = 5;
        int number = 12;
        int answer = -1;

        while (answer > 0) {
            int num = n*10+n;
            answer = calculate(Integer.toString(num), number);
        }
    }
}
