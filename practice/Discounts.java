import java.util.Arrays;

public class Discounts {
    public static void main(String[] args) {
        int[] p = {13000, 88000, 10000};
        int[] d = {30, 20};
//        int[] p = {32000, 18000, 42500};
//        int[] d = {50, 20, 65};

        int answer = 0;
        Arrays.sort(p);
        Arrays.sort(d);

        for (int i =1; i< p.length+1; i++ ) {
            int sale = d.length < i ? p[p.length - i] : p[p.length - i] - (p[p.length - i] * d[d.length - i] / 100);
            answer += sale;
        }
    }
}
