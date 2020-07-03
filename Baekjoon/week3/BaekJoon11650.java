package week3;

import java.util.*;
public class BaekJoon11650 {
    public static void main(String[] args) {
        TreeMap<Integer, ArrayList<Integer>> arr = new TreeMap<>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            ArrayList a = arr.getOrDefault(x, new ArrayList<>());
            a.add(y);
            arr.put(x, a);
        }
        Object[] mapkey = arr.keySet().toArray();
        Arrays.sort(mapkey);
        for (Integer key : arr.keySet()) {
            ArrayList<Integer> src = arr.get(key);
            mergeSort(src);
            arr.put(key, src);
            for (Integer val : arr.get(key)) {
                System.out.println(key + " " + val);
            }
        }
    }

    static void mergeSort(ArrayList arr) {
        sort(arr, 0, arr.size());
    }

    static void sort(ArrayList arr, int low, int high) {
        if (high - low < 2) {
            return;
        }
        int mid = (low + high) / 2;
        sort(arr, 0, mid);
        sort(arr, mid, high);
        merge(arr, low, mid, high);
    }

    static void merge(ArrayList<Integer> arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int t = 0, l = low, h = mid;

        while (l < mid && h < high) {
            if (arr.get(l) < arr.get(h)) {
                temp.add(t++, arr.get(l++));
            } else {
                temp.add(t++, arr.get(h++));
            }
        }

        while (l < mid) {
            temp.add(t++, arr.get(l++));
        }

        while (h < high) {
            temp.add(t++, arr.get(h++));
        }
        for (int i = low; i < high; i++) {
            arr.set(i, temp.get(i - low));
        }
    }
}


//5
//100000 100000
//9999 9999
//-100000 -100000
//-9999 -9999
//0 0