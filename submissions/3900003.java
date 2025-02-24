import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long[] memo = new long[60];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        for (int i = 0; i < n; i ++) {
            long one = readInt();
            long two = readInt();
            long three = readInt();
            long k = readInt();
            if (three - two == two - one) {
                System.out.println((one + (three - two)*(k-1) % mod) % mod);
            }
            else {
                System.out.println(one * quickpow(three/two, k - 1, mod) % mod);
            }

        }
    }

    static long quickpow(long x, long exp, long mod) {
        if(exp == 0) return 1;
        long t = quickpow(x, exp/2, mod);
        t = t*t % mod;
        if(exp % 2 == 0) return t;
        return t*x % mod;
    }



    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}