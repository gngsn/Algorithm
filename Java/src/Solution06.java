/* 섬 연결하기 : https://programmers.co.kr/learn/courses/30/lessons/42861
Kruskal

n개의 섬 사이에 다리를 건설하는 비용(costs)이 주어질 때,
최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용을 return 하도록 solution을 완성하세요.

다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다.
예를 들어 A 섬과 B 섬 사이에 다리가 있고, B 섬과 C 섬 사이에 다리가 있으면 A 섬과 C 섬은 서로 통행 가능합니다.
* */

import java.util.*;

class Solution06 {
    int getRoot(int[] root, int n) {
        if(root[n]== n) return n;
        return getRoot(root, root[n]);
    }

    boolean isCycle(int root[], int a, int b) {
        a = getRoot(root, a);
        b = getRoot(root, b);
        return a == b;
    }

    void unionRoot(int root[], int a, int b) {
        a = getRoot(root, a);
        b = getRoot(root, b);
        if (a < b) root[b] = a;
        else root[a] = b;
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;
        int[] root = new int[n];

        for (int i = 0; i < n; i++) root[i] = i;

        Arrays.sort(costs, (x, y) -> Integer.compare(x[2], y[2]));

        for (int i = 0; i < costs.length; i++) {
            if (!isCycle(root, costs[i][0], costs[i][1])) {
                unionRoot(root, costs[i][0], costs[i][1]);
                answer += costs[i][2];
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int[][] costs = {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}};
        int result = new Solution06().solution(4, costs);

        System.out.println(result);
    }
}
