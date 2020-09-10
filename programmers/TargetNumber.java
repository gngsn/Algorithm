public class TargetNumber {
    static int dfs(int prev, int index, int[] nums, int target){
        if (index >= nums.length) {
            if (prev == target) {
                return 1;
            }
            return 0;
        }
        int next = index+1;
        int answer = dfs(prev+nums[index], next, nums, target);
        answer += dfs(prev-nums[index], next, nums, target);
        return answer;
    }

    public static int solution(int[] numbers, int target) {
        int answer =0;
        int cur = numbers[0];

        answer += dfs(cur, 1, numbers, target);
        answer += dfs(-cur, 1, numbers, target);

        return answer;
    }

    public static void main(String[] arg){
        int[] nums = {1,1,1,1,1};
        int answer = solution(nums, 3);
        System.out.println(answer);
    }
}

