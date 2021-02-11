import java.math.BigInteger;
import java.util.*;

public class qn1 {
    public static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    // A simple method to evaluate Euler Totient Function
    public static int phi(int n)
    {
        BigInteger bn = BigInteger.valueOf(n);
        if (bn.isProbablePrime(10)) return n-1;
        int result = 1;
        for (int i = 2; i < n; i++)
            if (gcd(i, n) == 1){
                result++;
            }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] orders = new int[N];
        int i = 0;
        while (i < N) {
            sc.next();
            int order = Integer.parseInt(sc.next());
            orders[i] = order;
            i++;
        }
        int[] counts = new int[N];
        for (int a=0;a<N;a++) {
            if (a == 0){
                for (int j = 1; j<=orders[a]; j++){
                    counts[a] += phi(j);
                }
                counts[a] += 1;
            } else {
                counts[a] = counts[a-1];
                for (int k = orders[a-1]+1; k<=orders[a]; k++){
                    counts[a] += phi(k);
                }
            }

        }
        for (int p=0;p<N;p++){
            System.out.println(Integer.toString(p+1) + " " + Integer.toString(counts[p]));
        }
    }
}
