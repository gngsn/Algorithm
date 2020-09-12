//1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
//2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
//3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
//4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
//5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
//6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution1 {

    static public String solution(String new_id) {
        String base = new_id.toLowerCase();

        base = repl(base, "([~!@#$%^&*()=+[{]}:?,<>])", "");
        base = repl(base, "\\.+", ".");

        if(base.charAt(0) == '.'){
            base = base.substring(1);
        }

        if(base.length() > 0 && base.charAt(base.length()-1) == '.'){
            base = base.substring(0, base.length()-1);
        }

        if(base.equals("")) base="a";

        if(base.length() > 15) {
            base = base.substring(0, 15);
            if(base.charAt(base.length()-1) == '.') base = base.substring(0, base.length()-1);
        }

        while(base.length() < 3) base += base.charAt(base.length()-1);
        return base;
    }

    static String repl(String base, String regex, String rep){
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(base);
        return matcher.replaceAll(rep);
    }

    static public void main(String[] args) {
        String new_id = "...!@BaT#*..y.abcdefghijklm";
        String new_id1 = "z-+.^.";
        String new_id2 = "=.=";
        String new_id3 = "123_.def";
        String new_id4 = "abcdefghijklmn.p";
        // bat.y.abcdefghi
        System.out.println(solution(new_id4));
    }
}
