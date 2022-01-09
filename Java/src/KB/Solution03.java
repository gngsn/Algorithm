package KB;

import java.util.Arrays;

public class Solution03 {
    public int solution(String[][] schedule) {
        int answer = -1;



        return answer;
    }

    public static void main(String[] args) {
        String[][] schedule = {{"MO 12:00 WE 14:30", "MO 12:00", "MO 15:00", "MO 18:00"}, {"TU 09:00", "TU 10:00", "TU 15:00", "TU 18:00"}, {"WE 09:00", "WE 12:00", "WE 15:00", "WE 18:00"}, {"TH 09:30", "TH 11:30", "TH 15:00", "TH 18:00"}, {"FR 15:00", "FR 15:00", "FR 15:00", "FR 15:00"}};
        int result = new Solution03().solution(schedule);

        System.out.println(result);
    }
}
