import java.util.*;
import java.util.stream.Collectors;

class Solution02 {
    public String solution(int[] numbers) {
        String[] result = Arrays.stream(numbers).mapToObj(String::valueOf).toArray(String[]::new);

        Arrays.sort(result, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2+o1).compareTo(o1+o2);
            }
        });

        if (result[0].equals("0")) return "0";
        return String.join("", result);
    }

    public static void main(String[] args) {
        int[] numbers = {6, 10, 2};
        int[] numbers1 = {0, 0, 0};
        int[] numbers2 = {3, 30, 34, 5, 9};

        String result = new Solution02().solution(numbers1);

        System.out.println(result);
    }
}