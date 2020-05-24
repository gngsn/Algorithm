import java.math.BigInteger;
import java.util.Scanner;
public class BaekJoon15894 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger b = new BigInteger(sc.nextLine());
        System.out.print(b.multiply(new BigInteger("4")));
    }
}
