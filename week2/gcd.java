package week2;
import java.math.BigInteger;
import java.util.*;

public class gcd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        while (N-- > 0) { // unlike in C/C++, we have to use > 0 in (N-- > 0)
            BigInteger p = sc.nextBigInteger();
            String ch = sc.next(); // we ignore the division sign in input
            BigInteger q = sc.nextBigInteger();
            BigInteger gcd_pq = p.gcd(q);
            System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq));
    }
}}
