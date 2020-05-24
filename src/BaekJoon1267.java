import java.util.Scanner;
public class BaekJoon1267 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = sc.nextInt();
        int y = 0, m=0;
        for (int i=0; i<c;i++) {
            int s = sc.nextInt();
            y += (s/30+1)*10;
            m += (s/60+1)*15;
        }
        String a = y >= m ? "M "+m: "Y "+y;
        if (y==m) a = "Y "+a;
        System.out.print(a);
    }
}
