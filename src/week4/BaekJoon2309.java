package week4;

import java.util.Arrays;
import java.util.Scanner;

public class BaekJoon2309 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] h = new int[9];
        int total = 0;
        for (int i = 0; i < 9; i++) {
            h[i] = sc.nextInt();
            total += h[i];
        }
        Arrays.sort(h);
        for (int i = 0; i < 9; i++) {
            int t = total - h[i];
            if (t<100) continue;
            for (int j = i; j < 9; j++) {
                if (t-h[j] == 100) {
                    print(h, i, j);
                    i = 9;
                    break;
                }
            }
        }
    }
    static void print(int[] h, int i, int j) {
        for (int l = 0; l < 9; l++) {
            if (l != i && l != j ) {
                System.out.println(h[l]);
            }
        }
    }
}


//20
//        7
//        23
//        19
//        10
//        15
//        25
//        8
//        13