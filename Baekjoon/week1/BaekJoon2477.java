package week1;

import java.io.IOException;
import java.util.*;

public class BaekJoon2477 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[6];
        int h = 0;
        int w = 0;
        int idxw = -1;
        int idxh = -1;
        String inputStr = sc.nextLine();
        int cham = Integer.parseInt(inputStr);
        for (int i = 0; i < 6; i++) {
            String input =  sc.nextLine();
            String[] str = input.split(" ");
            int a = Integer.parseInt(str[0]);
            int n = Integer.parseInt(str[1]);
            if ( a == 1 || a == 2) {
                arr[i] = n;
                idxw =  w < n ? i : idxw;
                w = w < n ? n : w;
            } else {
                arr[i] = n;
                idxh =  h < n ? i : idxh;
                h = h < n ? n : h;
            }
        }
        int smW = arr[(idxh + 3)%6];
        int smH = arr[(idxw +3)%6];
        int answer = ((h * w) - (smH * smW)) * cham;
        System.out.println(answer);
    }
}