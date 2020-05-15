import java.util.HashMap;
import java.util.Scanner;

public class BaekJoon1475 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numStr =  sc.nextLine();
        Integer num = Integer.parseInt(numStr);
        Integer count = 0;
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (Integer i = 0; i < numStr.length(); i++) {
            Integer checkNum = num % 10;
            if (checkNum == 9 || checkNum == 6) {
                if (numMap.get(9) == null) numMap.put(9,0);
                if (numMap.get(6) == null) numMap.put(6,0);
                checkNum = numMap.get(9) > numMap.get(6) ? 6 : 9;
            }
            Integer getNum = numMap.get(checkNum) == null ? 1 : numMap.get(checkNum)+1;
            numMap.put(checkNum, getNum);
            num /= 10;
            count = count < getNum ? getNum : count;
        }
        System.out.println(count);
    }
}