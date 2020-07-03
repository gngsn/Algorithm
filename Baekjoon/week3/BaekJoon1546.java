package week3;
import java.util.ArrayList;
import java.util.Scanner;
public class BaekJoon1546 {
    public static void main(String[] arg){
        Scanner sc = new Scanner(System.in);
        ArrayList<Float> s = new ArrayList<>();
        int n = sc.nextInt();
        float sum = 0;
        float max =0;
        for (int i = 0; i < n; i++) {
            float score = sc.nextInt();
            s.add(score);
            max = max<score ? score:max;
        }
        for (int i = 0; i < s.size(); i++)
            sum += (s.get(i)/max)*100;
        System.out.println(sum/s.size());
    }
}
