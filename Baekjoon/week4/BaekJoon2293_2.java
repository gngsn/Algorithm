package week4;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class BaekJoon2293_2 {
    static int c =0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = br.read();
        int[] price = new int[n];
        int k = br.read();
        for (int i = 0; i<n; i++) {
            int p = br.read();
            price[i] = p;
        }
        backtracking(price, k, 0);
        System.out.println(c);
    }
    static void backtracking(int[] p, int k, int idx) {
        int pos = k/p[idx];
        if (k == 0) {
            c++;
            return;
        }
        if (idx == p.length-1) {
            if (k%p[idx] != 0) return;
            c++;
            return;
        }
        for (int i=0; i<pos+1; i++) {
            int ch = k - p[idx]*i;
            for (int pp : p) {
                if (ch%pp == 0) {
                    backtracking(p, ch, idx+1);
                    break;
                }
            }
        }
    }
}