/* 보행자 천국 : https://programmers.co.kr/learn/courses/30/lessons/1832
DP
* */

class Solution08 {
    int MOD = 20170805;

    public static void main(String[] args) {
        int[][] cityMap = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
        int result = new Solution08().solution(3, 6, cityMap);

        System.out.println(result);
    }

    int solution(int m, int n, int[][] cityMap) {
        int answer = 0, v = 0, h =0;
        Direction[][] dir = new Direction[m+1][n+1];

        for (int y=0; y <= m; y++)
            for (int x=0; x <= n; x++)
                dir[y][x] = new Direction();

        dir[1][1] = new Direction(1, 1);

        for (int y=1; y <= m; y++) {
            for (int x=1; x <= n; x++) {
                if (cityMap[y-1][x-1] == 0) {
                    v = h = (dir[y][x].ver + dir[y-1][x].ver + dir[y][x-1].hor) % MOD;
                } else if (cityMap[y-1][x-1] == 1) {
                    v = h = 0;
                } else {
                    v = dir[y-1][x].ver;
                    h = dir[y][x-1].hor;
                }
                dir[y][x].ver = v;
                dir[y][x].hor = h;
            }
        }

        return dir[m][n].ver % MOD;
    }

    class Direction {
        int ver = 0;
        int hor = 0;

        Direction() { }

        Direction(int ver, int hor) {
            this.ver = ver;
            this.hor = hor;
        }

        @Override
        public String toString() {
            return "(ver: "+ ver+", hor: "+hor+")";
        }
    }
}
