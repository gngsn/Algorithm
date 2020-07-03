package FS;

import java.lang.reflect.Array;
import java.util.*;

public class travelRoute {
    static private Map<String, ArrayList<String>> adj = new HashMap<>();
    static private Map<String, boolean[]> visited = new HashMap<>();
    static String[] answer;

    static String[] solution(String[][] tickets) {
        String[] answer = {};

        for (String[] t : tickets) {
            visited.put(t[0], new boolean[t[1].length()]);
            addEdge(t[0], t[1]);
        }
        System.out.println("size: " + adj.size());
        System.out.println("adj : " + adj);
        DFS("ICN");

        return answer;
    }

    static void DFS(String start) {
        Iterator<String> keys = adj.keySet().iterator();
        int i = 0;
        DFSUtil(start);
//        while( keys.hasNext() ) {
//            System.out.println(i);
//
//            i++;
//        }
    }

    static void DFSUtil(String start) {
        ArrayList<String> value = adj.get(start);
        for (int i = 0; i < value.size(); i++) {
            System.out.println(value.get(i));
            boolean[] v = visited.get(start);
            if (!v[i]) {
                v[i] = true;
                visited.put(start, v);
                DFS(value.get(i));
            }
        }
    }

    static void addEdge(String k, String v) {
        ArrayList<String> value = adj.get(k);
        if (value == null) {
            value = new ArrayList(Arrays.asList(v));
            value.add(v);
        }
        else
            for (int i=0; i< value.size(); i++) {
                System.out.println("value : "+ value);
                System.out.println("v : "+ v);
                System.out.println(v.compareTo(value.get(i)));
                // value.get(i) > v --> 1
                if (v.compareTo(value.get(i)) > 0) {
                    value.add(i, v);
                    break;
                }
            }
//        adj.put(k, value);
    }

    static public void main(String[] args) {
        String[][] tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
        String[][] tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
        solution(tickets2);
    }
}
