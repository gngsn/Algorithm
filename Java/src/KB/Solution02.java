package KB;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class Solution02 {

    String check(String s) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char temp = s.charAt(i);
            if(temp == ')' && !st.isEmpty() && st.peek() == '(') {
                st.pop();
            } else {
                st.push(temp);
            }
        }

        String ret = "";
        while(!st.isEmpty()) ret = st.pop() + ret;

        return ret;
    }

    boolean isComp(String s) {
        return check(s).length() < 1;
    }

    public long solution(String[] arr1, String[] arr2) {
        long answer = 0;

        int comp1 = 0, comp2 =0;
        boolean[] comp = new boolean[arr2.length];
        for (int i=0; i < arr1.length; i++) {
            arr1[i] = check(arr1[i]);

            if (arr1[i].length() == 0) comp1++;

            for (int j=0; j < arr2.length; j++) {
                if (comp[j]) continue;

                arr2[j] = check(arr2[j]);

                if (arr2[j].length() == 0) {
                    comp2++;
                    comp[j] = true;
                    if (arr1[i].isEmpty()) break;
                    else continue;
                }

                String w = arr1[i]+arr2[j];
                if (w.length() % 2 == 0 && isComp(w)) {
                    answer++;
                }
            }
        }

        return answer + (comp1 * comp2);
    }

    public static void main(String[] args) {
        String[] arr1 = {"()", "(()", ")()", "()"};
        String[] arr2 = {")()", "()", "(()"};
        long result = new Solution02().solution(arr1, arr2);

        System.out.println(result);
    }
}


//    public long solution(String[] arr1, String[] arr2) {
//        long answer = 0;
//        List<String> wrong1 = new ArrayList<>();
//        List<String> wrong2 = new ArrayList<>();
//
//        for (String a : arr1) {
//            String ch = check(a);
//            if (ch.length() > 0) {
//                wrong1.add(ch);
//            }
//        }
//
//        for (String a : arr2) {
//            String ch = check(a);
//            if (ch.length() > 0) {
//                wrong2.add(ch);
//            }
//        }
//
//        for (String w1 : wrong1) {
//            for (String w2 : wrong2) {
//                String w = w1+w2;
//                if (w.length() % 2 == 0 && isComp(w)) {
//                    System.out.println("w1 :" +w1 +", w2 : " + w2 + ", w : "+ w);
//                    answer++;
//                }
//            }
//        }
//        System.out.println("111 answer : " + answer);
//
//        return answer + (arr1.length - wrong1.size()) * (arr2.length - wrong2.size());
//    }