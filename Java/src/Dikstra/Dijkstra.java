package Dikstra;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Dijkstra {
    public static void main(String arg[]){
        int V = 5;
        int source = 0;

        List<List<Edge> > adj = new ArrayList<List<Edge>>();

        for (int i = 0; i < V; i++) {
            List<Edge> item = new ArrayList<Edge>();
            adj.add(item);
        }

        adj.get(0).add(new Edge(1, 9));
        adj.get(0).add(new Edge(2, 6));
        adj.get(0).add(new Edge(3, 5));
        adj.get(0).add(new Edge(4, 3));

        adj.get(2).add(new Edge(1, 2));
        adj.get(2).add(new Edge(3, 4));

        DPQ dpq = new DPQ(V);
        dpq.dijkstra(adj, source);
    }
}

class DPQ {
    private boolean[] visited;
    private PriorityQueue<Edge> pq;
    private int V;
    List<List<Edge>> adj;
    int dist[];

    public DPQ(int V){
        this.V = V;
        dist = new int[V];
        visited = new boolean[V];
        pq = new PriorityQueue<Edge>(V, new Edge());
    }

    public void dijkstra(List<List<Edge>> adj, int start){
        this.adj = adj;

        for (int i = 0; i < V; i++)
            dist[i] = Integer.MAX_VALUE;

        pq.add(new Edge(start, 0));

        dist[start] = 0;
        while (!pq.isEmpty()) {
            int current = pq.remove().end;
            visited[current] = true;

            for (int i = 0; i < adj.get(current).size(); i++) {
                Edge next = adj.get(current).get(i);

                if (!visited[next.end]) {
                    if (dist[current] + next.weight < dist[next.end]) {
                        dist[next.end] = dist[current] + next.weight;
                        pq.add(new Edge(next.end, dist[next.end]));
                    }
                }
            }

        }
    }
}

class Edge implements Comparator<Edge> {
    int end;
    int weight;

    Edge() {}

    Edge(int end, int weight) {
        this.end = end;
        this.weight = weight;
    }

    @Override
    public int compare(Edge edge1, Edge edge2) {
        return edge1.weight - edge2.weight; //ASC
    }
}