package naver;

import java.util.Arrays;

public class question1 {
    public static void main(String[] args) {
        int[] array1 = new int[]{-1, 1, 3, 3, 3, 2, 3, 2, 1, 0};
        int[] array2 = new int[]{7, 7, 7, 7, 7, 7};
        int[] array3 = new int[]{1, 3, 5, 7, 9};
        int[] array4 = new int[]{3, 2, 4, 2, 0, -2, 2};
        int a = solution(array1);
        System.out.println(a);
    }

    public static int solution(int[] A) {
        int count = 0;
        int start;
        int end;
        int[] d = new int[A.length - 1];
        int size = d.length;

        for (int i = 0; i < A.length -1 ; i++)
            d[i] = A[i + 1] - A[i];

        for (int i =0; i < size-1; i++) {
            if (d[i] == d[i+1]) {
                start = i;
                int j =i;
                while (j < size-1 && d[j] == d[j+1]) {
                    j++;
                }
                end = j;
                count += counting(end - start + 1);
                i = j;
            }
        }
        return count;
    }

    public static int counting(int size) {
        int count = 0;
        for (int i = 1; i < size; i++)
            count += i;
        return count;
    }
}