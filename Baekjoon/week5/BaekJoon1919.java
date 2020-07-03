package week5;

import java.util.Scanner;

public class BaekJoon1919 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String st = sc.nextLine();
        String com = sc.nextLine();
        int answer = 0;
        int[] str = new int[26];
        int[] comStr = new int[26];
        for (int i = 0; i < st.length(); i++) str[st.charAt(i) - 'a']++;
        for (int i = 0; i < com.length(); i++) comStr[com.charAt(i) - 'a']++;

        for (int i = 0; i < str.length; i++)
            if (str[i] != comStr[i]) {
                int sum = str[i] - comStr[i];
                answer += sum > 0 ? sum : -sum;
            }
        System.out.println(answer);
    }
}