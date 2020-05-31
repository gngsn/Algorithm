package week3;
import java.util.ArrayList;
import java.util.Scanner;

public class BaekJoon6603 {
    private static ArrayList<String> result = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;
            boolean[] visited = new boolean[n];
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            combination(arr, visited, 0, n, 6);
            result.add("\n");
        }
        for(String r: result)
            System.out.print(r);
    }
    private static void combination(int[] arr, boolean[] visited, int start, int n, int r) {
        if (r == 0) {
            addResultArray(arr, visited, n);
            return;
        }
        for (int i = start; i < n; i++) {
            visited[i] = true;
            combination(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }
    private static void addResultArray(int[] arr, boolean[] visited, int n) {
        String str = "";
        for (int i = 0; i < n; i++) {
            if (visited[i])
                str += arr[i] + " ";
        }
        str += "\n";
        result.add(str);
    }
}