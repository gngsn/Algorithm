package week3;

import java.util.HashMap;
import java.util.Scanner;
public class BaekJoon9625 {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<String, Integer> ab = new HashMap<>();
        ab.put("A", 1);
        ab.put("B", 0);
        while (n!=0) {
            int a = ab.get("A");
            int b = ab.get("B");
            ab.put("A", b);
            ab.put("B", b+a);
            n--;
        }
        System.out.println(ab.get("A")+" "+ab.get("B"));
    }
}
