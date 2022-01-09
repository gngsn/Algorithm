package KB;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution04 {
    public int solution(int[][] tower, int k) {
        int answer = 0;
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        ArrayList<Integer> list;

        for (int i = 0; i < tower.length; i++) {
            if (map.containsKey(tower[i][1])) {
                list = map.get(tower[i][1]);
            } else {
                list = new ArrayList<>();
            }
            list.add(tower[i][0]);
            map.put(tower[i][1], list);
        }

        for (Integer key : map.keySet() ) {
            List<Integer> li = map.get(key);
            if (li.size() == 1) {
                answer++;
                continue;
            }
            for (int i = 1; i < li.size(); i++) {
                if (li.get(i) - li.get(i-1) <= k) continue;
                answer++;
            }
            answer++;
        }
        return answer;
    }

    public static void main(String[] args) {
        int[][] tower = {{0,2}, {2,3}, {3,2}, {5,3}, {6,2}, {7,3}, {9,4}, {10,2}, {11,2}, {12,4}, {14,2}, {15,3}, {16,2}};
        int result = new Solution04().solution(tower, 3);

        System.out.println(result);
    }
}
