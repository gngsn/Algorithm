import java.util.ArrayList;
import java.util.Scanner;

public class BaekJoon13300 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String studentInfo = sc.nextLine();
        String[] info = studentInfo.split(" ");
        int total = Integer.parseInt(info[0]);
        int k = Integer.parseInt(info[1]);
        int answer = 0;
        ArrayList<Integer> female = new ArrayList<>(6);
        ArrayList<Integer> male = new ArrayList<>(6);
        for (int i = 0; i < total; i++) {
            String infoLine = sc.nextLine();
            String[] who = infoLine.split(" ");
            int g = Integer.parseInt(who[1])-1;
            int gender = Integer.parseInt(who[0]);
            if (gender == 0) {
                female.add(g, female.get(g)+1);
                if (female.get(g) == k) {
                    answer++;
                    female.add(g, 0);
                }
            } else {
                male.add(g, male.get(g)+1);
                if (male.get(g) == k) {
                    answer++;
                    male.add(g, 0);
                }
            }
        }
        for (int f : female)
            answer += f == 0 ? 0 : 1;
        for (int m : male)
            answer += m == 0 ? 0 : 1;
        System.out.println(answer);
    }
}
