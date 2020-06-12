package week4;

import java.util.LinkedList;
import java.util.Scanner;

public class BaekJoon3190 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int SNAKE = -1;
        int EMPTY = 0;
        int APPLE = 1;
        int m = 0; // 움직인 횟수 & 시간 카운팅
        int x = 0;
        int y = 0;
        int idx = 0;
        int leftRight = 1; // 오른쪽이 1, 왼쪽이 -1 아니면 0
        int upDown = 0; // 아래가 1, 위가 -1 아니면 0
        LinkedList<Pair> snake = new LinkedList<>();

        int n = sc.nextInt();
        int[][] nxn = new int[n][n];

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

        while (true) {
            nxn[x][y] = SNAKE;
            snake.offer(new Pair(x, y));
            // 이동 시간 증가
            m++;

            // 이동할 x 좌표와 y좌표를 설정
            x += upDown;
            y += leftRight;

            // 종료 조건
            if (x < 0 || y < 0 || x == n || y == n) break;
            if (nxn[x][y] == SNAKE) break;
            if (nxn[x][y] == APPLE) {
                nxn[x][y] = EMPTY;
            } else {
                // 만약, 사과를 먹지 않았다면 원래 있던 자리에서 없어지고 다음칸으로 이동
                Pair p = snake.poll();
                nxn[p.left][p.right] = EMPTY;
            }

            // 만약, 뱀이 이동경로를 바꿔야 한다면 경로 바꿔주기
            if (idx < sec.length && m == sec[idx]) {
                int temp;
                if (dir[idx].equals("D")) {
                    // 오른쪽으로 돌 때의 규칙
                    temp = leftRight;
                    upDown *= -1;
                } else {
                    // 왼쪽으로 돌 때의 규칙
                    temp = leftRight * -1;
                }
                leftRight = upDown;
                upDown = temp;
                idx++;
            }
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
}


//    static void print() {
//        for (int j = 0; j < nxn.length; j++) {
//            System.out.println(Arrays.toString(nxn[j]));
//        }
//    }