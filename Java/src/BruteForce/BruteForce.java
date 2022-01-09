package BruteForce;

import java.util.Arrays;
import java.util.LinkedList;

public class BruteForce {
    public static void main(String[] args) {
        int n = 4, r = 3;
        int[] arr = new int[]{1, 2, 3, 4};

        // 순열 (순서 고려)
        System.out.println("- 순열 :: swap -");
        int[] out = new int[r];
        perm(arr, 0, n, r);

        System.out.println("- 순열 :: output -");
        boolean[] visited = new boolean[n];
        perm2(arr, out, visited, 0, n, r);

        // 조합 (순서 고려 X)
        System.out.println("- 조합 - ");
        visited = new boolean[n];
        comb(arr, visited, 0, r);
    }

    // 조합
    private static void comb(int[] arr, boolean[] visited, int start, int r) {
        if (r == 0) {
            for (int i = 0; i < arr.length; i++)
                if (visited[i]) System.out.print(arr[i] + " ");
            System.out.println();
            return;
        }

        for (int i = start; i < arr.length; i++) {
            visited[i] = true;
            comb(arr, visited, i + 1, r - 1);
            visited[i] = false;
        }
    }

    static void perm(int[] arr, int depth, int n, int r) {
        if (depth == r) {
            for (int i = 0; i < r; i++)
                System.out.print(arr[i] + " ");
            System.out.println();
            return;
        }

        for (int i = depth; i < n; i++) {
            swap(arr, depth, i);
            perm(arr, depth + 1, n, r);
            swap(arr, depth, i);
        }
    }

    static void swap(int[] arr, int depth, int i) { //두 배열의 값을 바꾸는 Swap 함수
        int temp = arr[depth];
        arr[depth] = arr[i];
        arr[i] = temp;
    }


    static void perm2(int[] arr, int[] output, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            for (int i = 0; i < r; i++)
                System.out.print(output[i] + " ");
            System.out.println();
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            output[depth] = arr[i];
            perm2(arr, output, visited, depth + 1, n, r);
            visited[i] = false;
        }
    }

    //중복 조합 (순서관심없고 뽑은 유무만 생각 + 자기자신도 포함)
//    private static void reCombination(int[] reComArr, int n, int r, int index, int target) {
//        if(r==0){
//            for(int i : reComArr){
//                System.out.print(i+" ");
//            }
//            System.out.println();
//            return;
//        }
//        if(target == n)return;
//
//        reComArr[index] = target;
//        reCombination(reComArr, n, r-1, index+1, target);//뽑는경우
//        reCombination(reComArr, n, r, index, target+1);//안뽑는경우
//    }
//
//    //중복순열 (순서있게 배열 + 자시자신도 포함)
//    private static void rePermutation(int n, int r, LinkedList<Integer> rePerArr) {
//        if(rePerArr.size() == r){
//            for(int i : rePerArr){
//                System.out.print(i+" ");
//            }
//            System.out.println();
//            return;
//        }
//
//        for(int i=0; i<n; i++){
//            rePerArr.add(i);
//            rePermutation(n, r, rePerArr);
//            rePerArr.removeLast();
//
//        }
//    }

}
