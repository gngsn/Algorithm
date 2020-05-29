package week3;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class BaekJoon11650 {
    private static HashMap<Integer, ArrayList<Integer>> arr = new HashMap<>();
    private static ArrayList<Integer> tmp = new ArrayList<>();
    private static ArrayList<Integer> src = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0; i<n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            ArrayList a = arr.getOrDefault(x, new ArrayList<>());
            a.add(y);
            arr.put(x, a);
        }
        for(Integer key : arr.keySet()) {
            if (arr.get(key).size() > 1) {
                tmp = new ArrayList<>();
                src = arr.get(key);
                mergeSort(0, arr.get(key).size() - 1);
                arr.put(key, src);
            }
            for (Integer val : arr.get(key)) {
                System.out.println(key + " " + val);
            }
        }
    }
    static void mergeSort(int start, int end) {
        if (start<end) {
            int mid = (start+end) / 2;
            mergeSort(start, mid);
            mergeSort(mid+1, end);
            int p = start;
            int q = mid+1;
            int idx = p;
            while (p<=mid || q<=end) {
                System.out.println("src : "+src);
                System.out.println("q : "+q);
                if (q>end || (p<=mid && src.get(p) < src.get(q))) {
                    tmp.add(idx++, src.get(p++)) ;
                } else {
                    tmp.add(idx++, src.get(q++));
                }
            }
            src = tmp;
        }
    }
}
