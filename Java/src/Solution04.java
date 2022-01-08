/* 카펫 : https://programmers.co.kr/learn/courses/30/lessons/42842

Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

* */

import java.util.Arrays;
import java.util.HashSet;

class Solution04 {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        int nm = brown+yellow;

//        for (int i=1; i <= Math.sqrt(nm); i++) {
//            System.out.println("nm : " + nm + ", i : " + i);
//            if (nm % i == 0 && (i-2)*(nm/i-2) == yellow)
//                return new int[]{i, nm/i};
//        }

        int b = (brown+4)/2;
        int n1 = (int)(b + Math.sqrt(Math.pow(b, 2) - 4*(brown+yellow))) / 2;
        int m = (brown+yellow)/n1;

        return n1 < m? new int[]{n1, m} : new int[]{m, n1};
    }

    public static void main(String[] args) {
        int[] result = new Solution04().solution(8, 1);

        System.out.println(Arrays.toString(result));
    }
}