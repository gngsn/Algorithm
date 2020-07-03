package week1;

import java.util.HashMap;
import java.util.Scanner;

public class BaekJoon10807 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        HashMap<String, Integer> numMap = new HashMap<>();
        String input = sc.nextLine();
        String[] numArray = input.split(" ");
        for (String num : numArray) {
            Integer n = numMap.get(num);
            numMap.put(num, n == null ? 1 : n+1);
        }
        String findNum = sc.nextLine();
        Integer answer = numMap.get(findNum);
        System.out.println(answer == null ? 0 : answer);
    }
}