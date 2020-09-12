import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class TravelRoute {

    public static class Node {
        static String start;
        static String dest;
        static int edge;

        public Node(String start, String dest, int edge) {
            this.start = start;
            this.dest = dest;
            this.edge = edge;
        }
    }

    static String dfs(String start, int index, boolean[] visited, String[][] tickets) {
        String ss = "";
        Queue<Node> q = new LinkedList<>();
        int last = 10000;


        for (int i=0; i<tickets.length; i++) {
            String[] t = tickets[i];
            if (start == t[0]) {
                int ind = t[1].charAt(0) - '0';
                if (ind < last) last = ind;
                q.add(new Node(t[0], t[1], i));
            }
        }
        return ss;
    }

    static public String[] solution(String[][] tickets) {
        String[] answer = {};

        boolean[] visited = new boolean[tickets.length];
        String d = dfs("ICN", 0, visited, tickets);

        return answer;
    }

    static public void main(String[] args) {
        System.out.println('A'-'0');
        String[][] tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
        String[][] tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
        String[] dd = solution(tickets2);
        System.out.println(Arrays.toString(dd));
        System.out.println(dd);
    }
}
