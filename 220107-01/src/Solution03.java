import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;

class Solution03 {
    private int answer = 0;
    HashSet<Integer> hs = new HashSet<>();

    Boolean isPrime(int n) {
        if (n < 2) return false;
        for(int i=2; i <= Math.sqrt(n); i++)
            if ((n % i) == 0) return false;

            System.out.println("prime : " + n);
        return true;
    }

    void check(String base, String numbers, int len, boolean[] visited) {
        if (numbers.length() > 0) {
            Integer num = Integer.parseInt(numbers);
            if (!hs.contains(num)) {
                hs.add(num);

                if(isPrime(num)) answer++;
            }
        }

        for (int i=0; i < base.length(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            check(base, numbers + base.charAt(i), len+1, visited);
            visited[i] = false;
        }
    }

    public int solution(String numbers) {
        boolean[] visited = new boolean[numbers.length()];
        check(numbers, "", 0, visited);

        return answer;
    }

    public static void main(String[] args) {
        String numbers = "011";
        String numbers1 = "17";

        int result = new Solution03().solution(numbers1);

        System.out.println(result);
    }
}