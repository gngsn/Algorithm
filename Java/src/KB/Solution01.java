package KB;

import java.util.Arrays;

public class Solution01 {
    public int solution(int[][] fees, int usage) {
        int answer = 0;
        int acc = 0;
        fees[fees.length - 1][0] = 10001;

        for (int i = 0; i < fees.length; i++) {
            System.out.println("a : " + fees[i][0] + ", b : " + fees[i][1] + ", c : " + fees[i][2]);

            if (usage <= fees[i][0]) {
                answer += fees[i][1] + acc + (i==0? usage : (usage - fees[i - 1][0])) * fees[i][2];
                break;
            } else {
                int range = i == 0 ? fees[i][0] : fees[i][0] - fees[i - 1][0];
                acc += range * fees[i][2];
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int usage = 1205;
        int[][] fees = {{1851, 1000, 100}, {0, 2000, 155}};
//        int[][] fees = {{200, 910, 93}, {400, 1600, 188}, {655, 7300, 281}, {0, 15372, 435}};
        int result = new Solution01().solution(fees, usage);

        System.out.println(result);
    }
}
