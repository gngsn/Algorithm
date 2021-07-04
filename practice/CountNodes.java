import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class CountNodes {
    public static void main(String[] arg) {
        int n = 6;
        int[][] edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
        ArrayList<Integer> a[] = new ArrayList[++n];
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];

        int max = 0;
        int maxCount = 0;

        for (int[] e : edge) {
            if (a[e[0]] == null) a[e[0]] = new ArrayList<>();
            if (a[e[1]] == null) a[e[1]] = new ArrayList<>();
            a[e[0]].add(e[1]);
            a[e[1]].add(e[0]);
        }

        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        visited[0] = visited[1] = true;
        while(!q.isEmpty()) {
            int now = q.poll();

            for (int next:a[now]) {
                if (visited[next]) continue;
                visited[next] = true;
                q.offer(next);
                dist[next] = dist[now]+1;

                if (dist[next] > max) {
                    max = dist[next];
                    maxCount=1;
                } else if (dist[next] == max) {
                    maxCount++;
                }
            }

            System.out.println("dist : "+ Arrays.toString(dist));
            System.out.println("maxCount : "+ maxCount);
        }
    }
}
