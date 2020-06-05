package week4;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class BaekJoon3190 {
    static int[][] nxn;
    static int n = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int SNAKE = -1;
        int EMPTY = 0;
        int APPLE = 1;
        int m = 0;
        int x = 0;
        int y = 0;
        int s = 1;
        int idx = 0;
        int temp;
        int leftRight = 1; // 오른쪽이 1, 왼쪽이 -1 아니면 0
        int upDown = 0; // 아래가 1, 위가 -1 아니면 0
        LinkedList<Pair> snake = new LinkedList<>();

        n = sc.nextInt();
        nxn = new int[n][n];

        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int ax = sc.nextInt();
            int ay = sc.nextInt();
            nxn[ax - 1][ay - 1] = APPLE;
        }
        int l = sc.nextInt();
        int[] sec = new int[l];
        String[] dir = new String[l];
        for (int i = 0; i < l; i++) {
            sec[i] = sc.nextInt();
            dir[i] = sc.next();
        }
        System.out.println("sec : " + Arrays.toString(sec));
        System.out.println("dir : " + Arrays.toString(dir));

//        nxn[x][y] = SNAKE;
        snake.offer(new Pair(x, y));

        while (true) {
            m++;
            x += upDown;
            y += leftRight;
            if (x < 0 || y < 0 || x == n || y == n) break;
            if (nxn[x][y] == SNAKE) break;
            if (nxn[x][y] == APPLE) {
                nxn[x][y] = EMPTY;
            } else {
                Pair p = snake.poll();
                nxn[p.left][p.right] = EMPTY;
            }
            nxn[x][y] = SNAKE;
            snake.offer(new Pair(x, y));
            System.out.println("( x : " + x + " , y : " + y + " )");

            if (idx < sec.length && s == sec[idx]) {
                if (dir[idx].equals("D")) {
                    temp = leftRight;
                    upDown *= -1;
                } else {
                    temp = leftRight * -1;
                }
                leftRight = upDown;
                upDown = temp;
                idx++;
            }
            s++;
        }
        System.out.println(m);
    }
}

class Pair {
    final int left;
    final int right;

    public Pair(int left, int right) {
        this.left = left;
        this.right = right;
    }

    static Pair of(int left, int right) {
        return new Pair(left, right);
    }
}


//    static void print() {
//        for (int j = 0; j < nxn.length; j++) {
//            System.out.println(Arrays.toString(nxn[j]));
//        }
//    }