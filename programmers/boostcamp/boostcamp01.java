package boostcamp;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class boostcamp01 {
    static boolean solution(String[] name_list) {
        char[] n = {};
        for (int i=0; i<name_list.length; i++) {
            Pattern pattern1 = Pattern.compile("(^"+name_list[i]+")*");
            for (int j=i+1; j < name_list.length; j++) {
                Pattern pattern2 = Pattern.compile("(^"+name_list[j]+")*");
                Matcher m = pattern1.matcher(name_list[j]);
                if (m.find())
                    if (m.group(1) != null)
                        return true;

                m = pattern2.matcher(name_list[i]);
                if (m.find())
                    if (m.group(1) != null)
                        return true;
            }
        }
        return false;
    }


    public static void main(String args[]) {
        String[] animal = {"가을", "우주", "너굴"};
        String[] animal2 = {"봄", "여울", "봄봄"};
        String[] animal4 = {"봄봄", "여울", "봄"};
        String[] animal3 = {"너굴", "너울", "여울", "서울"};
        System.out.println(solution(animal3));
    }

}
