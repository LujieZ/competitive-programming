package week2;
import java.math.BigInteger;
import java.util.*;

public class mod_power {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); int c = sc.nextInt();
        while (c-- > 0) {
            BigInteger x = BigInteger.valueOf(sc.nextInt());
            BigInteger y = BigInteger.valueOf(sc.nextInt());
            BigInteger n = BigInteger.valueOf(sc.nextInt());
            System.out.println(x.modPow(y, n)); // (x^y) mod n
        }
    }
}
