import java.util.Iterator;
import java.util.LinkedList;

public class BFSwithGraph {
    private int V;
    private LinkedList<Integer>[] adj;

    BFSwithGraph(int s) {
        V=s;
        adj = new LinkedList[s];
        for(int i=0;i<s;i++)
            adj[i] = new LinkedList();
    }

    void addEdge(int i, int v) {
        adj[i].add(v);
    }

    void BFS(int n) {
        boolean[] visited = new boolean[V];
        LinkedList<Integer> queue = new LinkedList<>();
        visited[n] = true;
        queue.add(n);

        while(queue.size() != 0) {
            int s = queue.poll();
            System.out.println(s + " ");
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext()) {
                n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String[] args) {
        BFSwithGraph g = new BFSwithGraph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        g.BFS(2);
    }
}
