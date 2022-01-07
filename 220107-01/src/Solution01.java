import java.util.ArrayList;
import java.util.Arrays;

class Solution01 {
    int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        for (int i=0; i < commands.length; i++) {
            int[] result = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
            Arrays.sort(result);
            answer[i] = result[commands[i][2]-1];
        }
        Arrays.sort(answer);

        return answer;
    }

    public static void main(String[] args) {
        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        int[] result = new Solution01().solution(array, commands);

        System.out.println(Arrays.toString(result));
    }
}