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
