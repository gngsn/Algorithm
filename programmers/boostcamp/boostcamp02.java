package boostcamp;
import java.util.*;

public class boostcamp02 {
    static int[] solution(int[] arrayA, int[] arrayB) {
        int[] answer = new int[5];
        List<Integer> a = makeList(arrayA);
        List<Integer> b = makeList(arrayB);

        Set<Integer> ah = new HashSet();
        Set<Integer> bh = new HashSet();

        ah.addAll(a);
        bh.addAll(b);

        Set<Integer> s = sum(a, b);
        List<Integer> c = complement(a, b);
        List<Integer> i = intersaction(a, b);

        answer[0] = ah.size();
        answer[0] = bh.size();
        answer[0] = s.size();
        answer[0] = c.size();
        answer[0] = i.size();

        return answer;
    }

    static List<Integer> complement(List<Integer> base, List<Integer> other) {
        ArrayList<Integer> arr = new ArrayList<>();
        int i = 0;
        for(int b : base)
            if(!other.contains(b) && !arr.contains(b))
                arr.add(i++, b);
        if (arr.size() == 0)
            return base;
        return arr;
    }

    static ArrayList<Integer> intersaction(List<Integer> base, List<Integer> other) {
        ArrayList<Integer> arr = new ArrayList<>();
        int i = 0;
        for(int b : base) {
            if(other.contains(b) && !arr.contains(b)) {
                arr.add(i++, b);
            }
        }
        return arr;
    }

    static Set<Integer> sum(List<Integer> base, List<Integer> other) {
        Set<Integer> s = new HashSet();
        s.addAll(base);
        s.addAll(other);

        return s;
    }

    static List<Integer> makeList(int[] arr) {
        List<Integer> b = new ArrayList<>();
        for (int a: arr)
            b.add(a);
        return b;
    }

    static public void main(String[] args) {
        int[] a = {1, 2, 3, 2};
        int[] b = {1, 3};
        int[] a2 = {2,3,4,3,5};
        int[] b2 = {1,6,7};

        System.out.println(solution(a2, b2));
    }
}