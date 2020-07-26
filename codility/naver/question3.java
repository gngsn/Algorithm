package naver;

public class question3 {
    public static void main (String[] args) {
        int a = 268;
        int b = 670;
        int c = -999;
        int aa = solution(c);
        System.out.println(aa);
    }

    public static int solution(int A) {
        int max = -8001;
        String strA = Integer.toString(A);
        for (int i=0; i<strA.length(); i++) {
            StringBuffer sb = new StringBuffer();
            if (A < 0) {
                sb.append("-").append(strA.substring(1,i+1)).append('5').append(strA.substring(i+1,strA.length()));
            } else {
                sb.append(strA.substring(0,i)).append('5').append(strA.substring(i,strA.length()));
            }
            int result = Integer.parseInt(sb.toString());
            if (max < result) max = result;
        }
        return max;
    }

}
