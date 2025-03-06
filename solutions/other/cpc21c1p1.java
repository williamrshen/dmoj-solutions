import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int t = readInt();
        for (int i = 0; i < t; i ++) {
            long n = readLong();
            long d = readLong();
            d /= gcd(n,d);
            int[] p = new int[5];
            for (int j = 2; j <= 5; j += 3) {
                while (d%j == 0) {
                    d = d/j;
                    p[j-1] ++;
                }
            }
            if (d != 1) {
                System.out.println(-1);
            } else {
                System.out.println(Math.max(p[1],p[4]));
            }
        }
    }

    public static long gcd (long a, long b) {
        if (b == 0) return a;
        return gcd(b, a%b);
//        while (a != 0 && b!= 0) {
//            if (a > b) {
//                a = a%b;
//            } else if (b > a) {
//                b = b%a;
//            }
//        }
//        return Math.max(a,b);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}