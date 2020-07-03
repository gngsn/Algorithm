package week2;

import java.lang.reflect.Array;
import java.util.*;
public class BaekJoon10804 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> c = new ArrayList<>(20);
        for (int i=1; i<21; i++) c.add(i);
        for (int i=0;i<10;i++) {
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
            while (a<=b) {
                Collections.swap(c, a, b);
                a++; b--;
            }
        }
        for (int i=0; i<20; i++) System.out.print(c.get(i)+" ");
    }
}