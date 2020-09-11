import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.regex.Pattern;

public class ReplaceWordBFS {
    static class Node {
        String next;
        int edge;

        public Node(String next, int edge) {
            this.next = next;
            this.edge = edge;
        }
    }

    static public int solution(String begin, String target, String[] words) {
        int answer = 0;
        Queue<Node> q = new LinkedList<>();

        boolean[] isAdd = new boolean[words.length];
        q.add(new Node(begin, 0));


        while(!q.isEmpty()) {
            System.out.println(q.peek().next);
            System.out.println(q.peek().edge);
            Node n = q.poll();

            if (n.next.equals(target)) {
                answer = n.edge;
                break;
            }

            for (int i =0; i< words.length; i++) {
                if (!isAdd[i] && isOneDiffer(n.next, words[i])) {
                    isAdd[i] = true;
                    q.add(new Node(words[i], n.edge+1));
                }
            }
        }

        return answer;
    }


    static boolean isOneDiffer(String base, String com) {
        for (int i = 0; i < base.length(); i++) {
            StringBuilder beginRegex = new StringBuilder(base);
            beginRegex.setCharAt(i, '.');
            if (Pattern.matches(beginRegex.toString(), com))
                return true;
        }
        return false;
    }

    static public void main(String[] args) {
        String b = "hit";
        String t = "cog";
        String[] w = {"hot", "dot", "dog", "lot", "log", "cog"};
        String[] w1 = {"hot", "dot", "dog", "lot", "log"};
        int dd = solution(b, t, w);
        System.out.println(dd);
    }
}
