package week1;

import java.util.Scanner;
public class BaekJoon10162 {
    public static void main(String[] args) {
        Integer[] button = {300, 60, 10};
        String answer;
        Scanner sc = new Scanner(System.in);
        String timeStr =  sc.nextLine();
        Integer time = Integer.parseInt(timeStr);
        answer = time / button[0] + " ";
        time %= button[0];
        answer += time / button[1] + " ";
        time %= button[1];
        answer += time / button[2];
        time %= button[2];
        answer = time != 0 ? "-1" : answer;
        System.out.println(answer);
    }
}
