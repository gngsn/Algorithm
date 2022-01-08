/* 배달 : https://programmers.co.kr/learn/courses/30/lessons/12978
Dikstra!!


N개의 마을로 이루어진 나라가 있습니다. 이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다.
각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다.
도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다.
각 마을로부터 음식 주문을 받으려고 하는데, N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다.
다음은 N = 5, K = 3인 경우의 예시입니다.

위 그림에서 1번 마을에 있는 음식점은 [1, 2, 4, 5] 번 마을까지는 3 이하의 시간에 배달할 수 있습니다.
그러나 3번 마을까지는 3시간 이내로 배달할 수 있는 경로가 없으므로 3번 마을에서는 주문을 받지 않습니다.
따라서 1번 마을에 있는 음식점이 배달 주문을 받을 수 있는 마을은 4개가 됩니다.
마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때,
음식 주문을 받을 수 있는 마을의 개수를 return 하도록 solution 함수를 완성해주세요.
* */

import java.util.*;

class Solution05 {
    int[] dijkstra(int N, List<List<Node>> adj, int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>(N, new Node());
        boolean[] visited = new boolean[N];
        int dist[] = new int[N];

        for (int i = 0; i < N; i++)
            dist[i] = Integer.MAX_VALUE;

        pq.add(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            int cur = pq.remove().end;
            visited[cur] = true;

            for (int i=0; i < adj.get(cur).size(); i++) {
                Node next = adj.get(cur).get(i);

                if (visited[next.end]) continue;
                if (dist[cur] + next.dist < dist[next.end]) {
                    dist[next.end] = dist[cur] + next.dist;
                    pq.add(new Node(next.end, dist[next.end]));
                }
            }
        }

        return dist;
    }

    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        List<List<Node>> adj = new ArrayList<List<Node>>();

        for (int i = 0; i <= N; i++)
            adj.add(new ArrayList<Node>());

        for (int[] ro : road) {
            adj.get(ro[0]).add(new Node(ro[1], ro[2]));
            adj.get(ro[1]).add(new Node(ro[0], ro[2]));
        }

        int[] dist = dijkstra(N+1, adj, 1);

        for (int i = 1; i < N+1; i++)
            if (dist[i] <= K) answer++;

        return answer;
    }

    public static void main(String[] args) {
        int[][] road = {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}};
        int result = new Solution05().solution(5, road, 3);

        System.out.println(result);
    }
}

class Node implements Comparator<Node> {
    int end;
    int dist;

    Node() {}

    Node(int end, int dist) {
        this.end = end;
        this.dist = dist;
    }

    @Override
    public String toString() {
        return "end: " + this.end + ", dist : " + this.dist;
    }

    @Override
    public int compare(Node n1, Node n2) {
        return n1.dist - n2.dist;
    }
}