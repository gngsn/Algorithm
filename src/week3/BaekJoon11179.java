package week3;

import java.util.ArrayList;
import java.util.Scanner;
public class BaekJoon11179 {
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int answer =0;
        ArrayList<Integer> b = new ArrayList<>();
        while (n != 0) {
            b.add((n % 2));
            n/=2;
        }
        for(int i=0; i< b.size(); i++){
            answer += (b.get(i) * Math.pow(2, (b.size()-1) - i));
        }
        System.out.println(answer);
    }
}