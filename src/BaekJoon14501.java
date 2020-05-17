import java.util.Scanner;
public class BaekJoon14501 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] p;
        int count = sc.nextInt();
        int max = 0;
        p = new int[count+10][3];
        for(int i=1; i<=count; i++){
            p[i][0] = sc.nextInt();
            p[i][1] = sc.nextInt();
        }
        for (int i=1; i<=count+1; i++) {
            p[i][2] = Math.max(max, p[i][2]);
            if (i+p[i][0] <= count+1) {
                p[i+p[i][0]][2] = Math.max(p[i+p[i][0]][2], p[i][2] + p[i][1]);
            }
            max = max < p[i][2] ? p[i][2] : max ;
        }
        System.out.println(max);
    }
}


//import java.util.Scanner;
//public class BaekJoon14501 {
//    static int[][] p;
//    static int count;
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        count = sc.nextInt();
//        p = new int[count+2][2];
//
//        for(int i=1; i<=count; i++){
//            p[i][0] = sc.nextInt();
//            p[i][1] = sc.nextInt();
//        }
//        System.out.println(findMaxP(1));
//    }
//
//    public static int findMaxP(int i) {
//        if (i == count && p[i][0] == 1) return p[i][1];
//        if (i+1 > count) return 0;
//        int next = i+p[i][0];
//        if (next-1 > count) return 0;
//        return Math.max(findMaxP(i+1) ,p[i][1] + findMaxP(next));
//    }
//}