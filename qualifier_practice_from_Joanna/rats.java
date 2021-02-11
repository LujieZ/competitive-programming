import java.math.BigInteger;
import java.util.*;

public class rats {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int a=1;a<=N;a++) {
            Set<BigInteger> hash_set = new HashSet<BigInteger>();
            sc.next();
            int M = sc.nextInt();
            BigInteger init = sc.nextBigInteger();
            BigInteger cur = init;
            int j=2;
            int flag = 1;

            hash_set.add(init);
            String init_str = init.toString();
            String sub_init_str = init_str.length() <= 8? "" : init_str.substring(4,init_str.length()-4);
            if (
                    init_str.length()>=8 &&
                        ((init_str.substring(0,4).equals("1233")
                                && init_str.substring(init_str.length()-4).equals("4444")
                                && sub_init_str.replaceAll("3", "").equals(""))
                        || (init_str.substring(0,4).equals("5566")
                                && init_str.substring(init_str.length()-4).equals("7777")
                                && sub_init_str.replaceAll("6", "").equals("")))){
                System.out.println(a+" C "+1);
                flag = 0;
            }

            while(j<=M && flag == 1){
                String M_str = cur.toString();
                // reverse
                StringBuilder input1 = new StringBuilder();
                input1.append(M_str);
                input1.reverse();
                BigInteger reversed_M = new BigInteger(input1.toString());
                // sum them up
                BigInteger total = cur.add(reversed_M);
                String total_str = total.toString();
                // Sort
                char[] chars = total_str.toCharArray();
                Arrays.sort(chars);
                String sorted = new String(chars);
                // remove leading zeros
                sorted = sorted.replaceFirst("^0+(?!$)", "");
                String sub_sorted = sorted.length() <= 8? "" : sorted.substring(4,sorted.length()-4);
                // System.out.println(sorted + " testing");
                BigInteger total_sorted = new BigInteger(sorted);
                cur = total_sorted;
                if (hash_set.contains(cur)) {
                    System.out.println(a+" R "+j);
                    flag = 0;
                } else if (
                        sorted.length()>=8 &&
                            ((sorted.substring(0,4).equals("1233")
                                && sorted.substring(sorted.length()-4).equals("4444")
                                && sub_sorted.replaceAll("3", "").equals(""))
                        || (sorted.substring(0,4).equals("5566")
                                && sorted.substring(sorted.length()-4).equals("7777")
                                && sub_sorted.replaceAll("6", "").equals("")))){
                    System.out.println(a+" C "+j);
                    flag = 0;
                }
                hash_set.add(cur);
                j++;
            }
            if (flag == 1) System.out.println(a+" "+cur);
        }
    }
}
