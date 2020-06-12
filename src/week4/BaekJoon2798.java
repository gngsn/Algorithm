package week4;

import java.util.Scanner;

public class BaekJoon2798 {
    static int m;
    static int min;
    static int d=300000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        m = sc.nextInt();
        int[] card = new int[n];
        for (int i=0; i<n; i++) {
            card[i] = sc.nextInt();
        }
        boolean[] visited = new boolean[n];
        combination(card, visited, 0, n, 3);
        System.out.println(min);
    }
    static void combination(int[] arr, boolean[] visited, int start, int n, int r) {
        if (r == 0) {
            int t = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]){
                    t += arr[i];
                }
            }
            if (m==t) {
                min = t;
                return;
            }
//            System.out.println("\n\nt : "+ (m-t));
//            System.out.println("min : "+ d);
            if ((m-t > 0) && (m-t < d)) {
                min = t;
                d = m-t;
            }
            return;
        }
        for (int i = start; i < n; i++) {
            visited[i] = true;
            combination(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }
}
