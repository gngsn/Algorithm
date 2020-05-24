import java.util.Arrays;
import java.util.Scanner;
public class BaekJoon2178 {
    static int[][] maze;
    static int r,c;
    static int a=1;
    static Boolean findPath(int x, int y, int n) {
        if (x<0||y<0||x>r-1||y>c-1||maze[x][y] == 0) {
            return false;
        }
        a = n > a ? n : a;
        if (x==r-1&&y==c-1) {
            System.out.println("\nx : "+x);
            System.out.println("y : "+y);
            System.out.println("n : "+n);
            return true;
        }
        maze[x][y] = 0;
        if (findPath(x,y-1, n+1) || findPath(x+1, y, n+1)|| findPath(x,y+1, n+1) || findPath(x-1, y, n+1)) {
            System.out.println("\nx : "+x);
            System.out.println("y : "+y);
            System.out.println("n : "+n);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] input =sc.nextLine().split(" ");
        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        maze = new int[r][c];
        for (int i=0;i<r;i++) {
            String[] array = sc.nextLine().split("");
            int b=0;
            for (String j:array) {
                maze[i][b] = Integer.parseInt(j);
                b++;
            }
            System.out.println(Arrays.toString(maze[i]));
        }
        findPath(0,0,0);
        System.out.print(a);
    }
}
