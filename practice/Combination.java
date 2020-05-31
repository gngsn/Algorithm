import java.io.*;
import java.util.Arrays;

class Combination {
    static void combinationUtil(int[] arr, boolean[] visited, int start, int n, int r) {
        System.out.println("start : "+ start +", r : "+ r);
        System.out.println("visited : "+ Arrays.toString(visited));
        if (r == 0) {
            for (int i = 0; i < n; i++) {
                if (visited[i])
                    System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = start; i < n; i++) {
            visited[i] = true;
            combinationUtil(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }

    static void printCombination(int[] arr, int n, int r) {
        boolean[] visited = new boolean[n];
        System.out.println("n : "+ n);

        combinationUtil(arr, visited, 0, n, r);
    }

    public static void main (String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int r = 3;
        int n = arr.length;
        printCombination(arr, n, r);
    }
}