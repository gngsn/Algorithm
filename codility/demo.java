import java.lang.reflect.Array;
import java.util.Arrays;

public class demo {
    public static void main (String[] args) {
        int[] array = new int[]{1,4,3,5,2};
//        solution(array);
        String str = new String();
        for (int i=0; i<50; i++)
            str += "*";
        System.out.println(str);
    }

    public static int solution(int[] A) {
        Arrays.sort(A);
        System.out.println(Arrays.toString(A));
        if (A[A.length] < 1) return 1;
        int com =1;
        for (int i = 0; i < A.length; i++ ) {
            if (A[i] == com) com++;
            else if (A[i] < com) {}
        }
        return 4;
    }
}
