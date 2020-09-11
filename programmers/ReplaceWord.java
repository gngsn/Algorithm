import java.util.regex.Pattern;

public class ReplaceWord {

    static int dfs(String begin, String target, int index, boolean visited[], String[] words, int cnt) {
        if (begin.equals(target))
            return cnt;

        if (visited[index])
            return cnt;

        visited[index] = true;

        int ans = 0;
        for (int i = 0; i < words.length; i++) {
            if (index != i && isOneDiffer(begin, words[i]) && !visited[i]) {
                ans = dfs(words[i], target, i, visited, words, cnt + 1);
            }
        }
        return ans;
    }

    static public int solution(String begin, String target, String[] words) {
        int v = words.length + 1;
        int answer = v;

        for (int i = 0; i < words.length; i++) {
            boolean[] visited = new boolean[v];
            if (isOneDiffer(begin, words[i])) {
                answer = Math.min(answer, dfs(words[i], target, i, visited, words, 1));
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
        solution(b, t, w1);
    }


//    static void makeAdj(int index, String word, String[] w){
//        for (int i=0; i<word.length(); i++) {
//            StringBuilder beginRegex = new StringBuilder(word);
//            beginRegex.setCharAt(i, '.');
//            for (int j=0; j < w.length; j++)
//                if (Pattern.matches(beginRegex.toString(), w[j]) && !adj[index].contains(j))
//                    addEdge(index, j);
//        }
//    }
}
