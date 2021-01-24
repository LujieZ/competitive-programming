package week2;
import java.math.BigInteger;
import java.util.*;

public class prime_testing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()){
            int N = sc.nextInt();
            BigInteger BN = BigInteger.valueOf(N);
            String R = new StringBuffer(BN.toString()).reverse().toString(); // reversed number
            int RN = Integer.parseInt(R);
            BigInteger BRN = BigInteger.valueOf(RN);
            if (!BN.isProbablePrime(10)) System.out.println("not prime");
            else if (N != RN && BRN.isProbablePrime(10)) System.out.println("emirp");
            else System.out.println("prime");
        }
    }
}
