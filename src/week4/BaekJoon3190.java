package week4;
import java.util.Scanner;
public class BaekJoon3190 {
    static Scanner sc = new Scanner(System.in);
    static int[][] nxn;
    static int n =0;
    static int SNAKE = -1;
    static int snakeLength = 1;
    static int leftRight = 1; // 오른쪽이 1, 왼쪽이 -1 아니면 0
    static int upDown = 0; // 아래가 1, 위가 -1 아니면 0

    public static void main(String[] args) {
        n = sc.nextInt();
        nxn = new int[n+1][n+1];
        int APPLE = 1;
        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            nxn[x][y] = APPLE;
        }
        int line = sc.nextInt();
        System.out.println("\n\nanswer : "+ letsGo(line));
    }

    static int letsGo(int l) {
        int move = 0;
        int x = 1;
        int y = 1;
        int temp;
        int sec = 0;
        for (int i = 0; i < l; i++) {
            int s = sc.nextInt() - sec;
            String c = sc.next();
            if (c.equals("D")) {
                if (leftRight != 0) {
                    temp = leftRight;
                } else {
                    temp = leftRight;
                    upDown *= -1;
                }
            } else {
                if (leftRight != 0) {
                    temp = leftRight * -1;
                } else {
                    temp = leftRight;
                }
            }
            leftRight = upDown;
            upDown = temp;
            System.out.println("c : "+c);
            System.out.println("leftRight : "+leftRight);
            System.out.println("upDown : "+upDown);
            for (int j=0; j < s; j++) {
                move++;
                x += leftRight;
                y += upDown;
                if ( x * y == 0 || x > n || y > n) return move;
                System.out.println("( x : "+x+" , y : "+y + " )");
                nxn[x][y] = SNAKE;
            }
            sec = s;
            System.out.println("move : " + move);
        }
        return move;
    }
}
