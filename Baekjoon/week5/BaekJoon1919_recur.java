package week5;

import java.util.Scanner;
public class BaekJoon1919_recur {
    static int answer = 999*2;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String st = sc.nextLine();
        String com = sc.nextLine();
        check(st, 0, st.length(), com);
        System.out.println(answer);
    }

    static void check(String str, int start, int end, String comStr) {
        if (start == end) return;
        if (comStr.contains(str.substring(start, end))) {
            int com = str.length() - (end - start) + comStr.length() - (end - start);
            if (answer > com) {
                answer = com;
            }
        }
        check(str, start + 1, end, comStr);
        check(str, start, end - 1, comStr);
    }
}