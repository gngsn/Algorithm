package week4;
import java.util.Arrays;
import java.util.Scanner;

public class BaekJoon2293 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] c= new int[n+1];
        int[] d = new int[k+1];
        d[0] = 1;
        for (int i = 0; i<n; i++)
            c[i] = sc.nextInt();

        for (int i =0; i < n; i++) {
            for (int j=0; j <= k; j++) {
                if (j >= c[i]) {
                    d[j] += d[j-c[i]];
                }
            }
        }
        System.out.println(d[d.length-1]);
    }
}