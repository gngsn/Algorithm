package naver;

import java.util.ArrayList;

import static java.lang.Character.toUpperCase;

public class question2 {
    public static void main (String[] args) {
        String a = "azABaabza";
        String b = "TacoCat";
        int s = solution(a);
        System.out.println(s);
    }

    public static int solution(String S) {
        StringBuffer little = new StringBuffer("");
        StringBuffer large = new StringBuffer("");
            for (int i = 0; i< S.length(); i++) {
            char c = S.charAt(i);
            if ('z'-c > 30) {
                large.append(c);
            } else {
                little.append(c);
            }
        }
        check(little, large, S, 0, S.length());

        System.out.println("little : "+ little);
        System.out.println("large : "+large);
        return 2;
    }

    public static int check (StringBuffer little, StringBuffer large, String S, int start, int end) {
        String str = S.substring(start, end);
        String n = Character.toString(little.charAt(start)).toUpperCase();
        if (large.indexOf(n) < 0) {
            int d = S.indexOf(n);
            check(little, large, str, 0, d);
            check(little, large, str, d + 1, str.length());
        }
        return str.length();
    }
}
