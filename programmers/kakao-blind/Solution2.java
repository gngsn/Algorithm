import java.util.*;
import java.util.ArrayList;
import java.util.regex.Pattern;

public class Solution2 {

    static public String[] solution(String[] orders, int[] course) {
        ArrayList<String> a = new ArrayList<>();
        for(int i=orders.length-1; i>0; i--) {
            check(orders[i], i, orders, course, a);
        }
        Collections.sort(a);
        String[] answer = new String[a.size()];
        for (int i =0; i < a.size(); i++)
            answer[i] = a.get(i);
        return answer;
    }

    static void check(String base, int index, String[] orders, int[] course, ArrayList<String> answer) {
        if(base.length() < 2) return;
        String regex ="";

        for(int i =0; i<base.length()-1; i++) {
            regex += "["+base +"]\\w*";
        }
        regex += "["+base+"]";

        System.out.println("regex : "+regex);

        int count = 0;
        for(int i =0; i<orders.length;i++){
            System.out.println("order : "+orders[i]);
            if ( i != index && Pattern.matches(regex, orders[i])){
                count++;
                System.out.println("count : "+count);
            }
        }

        for (int c : course) {
            if (base.length() == c && count > 1) {
                answer.add(base);
            }
        }
        check(base.substring(0, base.length()-1), index, orders, course, answer);
    }

//    static public String[] solution(String[] orders, int[] course) {
//        String[] answer = {};
//        HashMap<Character, Integer> count = new HashMap<>();
//        String[] list = new String[20];
//        for (String order : orders) {
//            putHash(order, count);
//        }
//
//        for (Character s : count.keySet()) {
//            int index = count.get(s);
//            if (list[index] == null) list[index] = "";
//            list[index] = list[index] + s;
//        }
//
//        System.out.println(Arrays.toString(list));
//
//        ArrayList<String> a = new ArrayList<>();
//        boolean[] visited = new boolean[list.length];
//        for (int i = 0; i < list.length; i++) {
//            dfs(list[i], i, list, visited, course, a);
//        }
//
//        System.out.println(a);
//
//        return answer;
//    }

//    static void dfs(String base, int index, String[] list, boolean visited[], int[] course, ArrayList<String> answer) {
////        System.out.println(Arrays.toString(visited));
//        if (list[index] == null) return;
//        if (visited[index]) return;
//        for (int c : course) {
//            if (base.length() == c) {
//                visited[index] = true;
//                answer.add(base);
//            }
//        }
//        dfs(base + list[index + 1], index + 1, list, visited, course, answer);
//    }

    static void putHash(String order, HashMap<Character, Integer> count) {
        for (int i = 0; i < order.length(); i++) {
            int v = count.getOrDefault(order.charAt(i), 0);
            count.put(order.charAt(i), v + 1);
        }
    }

    static public void main(String[] args) {
//        String[] o = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
//        "XYZ", "XWY", "WXA"
        String[] o = {"XYZ", "XWY", "WXA"};
        int[] c = {2, 3, 4};
        String[] dd = solution(o, c);
        System.out.println(Arrays.toString(dd));
    }
}
