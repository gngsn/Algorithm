package week5;

import java.util.Scanner;
public class BaekJoon5622 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String al = sc.next();
        int s = 0;
        for (int i = 0; i < al.length(); i++) {
            int a = (al.charAt(i) - 'A');
            a = a > 17 ? a == 25? a-2: a-1 : a;
            s += a / 3 + 1 + 2;
        }
        System.out.println(s);
    }
}

// ABC | DEF | GHI | JKL | MNO | PQRS | TUV | WXYZ
// 012 | 345 | 678 | 901 | 234 | 5678 | 901 | 2345
//  2     3     4     5     6     7      8      9