public class Network {
    public static int dfs(int n, int index, int[][] coms, boolean[] visited) {
        if (visited[index]) return 0;
        visited[index] = true;
        System.out.println(index);


        for (int i=0; i<n; i++) {
            if (coms[index][i]==1){
                dfs(n, i, coms, visited);
            }
        }
        return 1;
    }

    public static int solution(int n, int[][] computers) {
        int answer =0;
        boolean[] visited = new boolean[n];
        for (int i=0; i<n; i++) {
            answer += dfs(n, i, computers, visited);
        }
        return answer;
    }
    public static void main(String[] arg){
        int[][] com = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        int[][] com2 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
        int answer = solution(3, com);
        System.out.println(answer);
    }
}



//class Solution {
//        public static int dfs(int index, int[][] coms, boolean[] visited) {
//        if (visited[index]) return 0;
//        visited[index] = true;
//
//        for (int i=0; i<coms.length; i++)
//            if (coms[index][i]==1)
//                dfs(i, coms, visited);
//        return 1;
//    }
//
//    public static int solution(int n, int[][] computers) {
//        int answer = 0;
//        boolean[] visited = new boolean[n];
//        for (int i=0; i<n; i++)
//            answer += dfs(i, computers, visited);
//        return answer;
//    }
//}