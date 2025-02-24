import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int x;
    public static void main(String[] args) throws IOException {
        int n = readInt(), k = readInt(), m = 0, ans = 0;
        Integer b[] = new Integer[n];
        for (int i = 0; i < n; i ++) { b[i] = readInt(); m = Math.max(m, b[i]); }
        for (int i = 1; i <= m; i ++) {
            int f = 0;
            for (int j = 0; j < n; j ++) f += b[j] / i;
            if (f < k / 2) break;
            if (f >= k) { ans = Math.max(ans, i * k / 2); continue; }
            x = i;
            Arrays.sort(b, new cmp());
            int c = i * (f - k / 2);
            for (int j = 0; j < n && j + f < k; j ++) c += b[j] % i;
            ans = Math.max(ans, c);
        }
        System.out.println(ans);
    }

    static class cmp implements Comparator<Integer> {
        public int compare (Integer a, Integer b) {
            return (b % x) - (a % x);
        }
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }

// cool stuffs

    static long pow(long x, long n) {
        if(n == 0) return 1;
        long t = pow(x, n/2);
        t = t*t;
        if(n % 2 == 0) return t;
        return t*x;
    }

    public static int gcd (int a, int b) {
        return b == 0 ? a : gcd (b, a % b);
    }

    public static int lcm (int a, int b) {
        return a * b / gcd (a, b);
    }

    public static int fast_pow_mod (int b, int x, int mod) {
        if (x == 0) return 1;
        if (x == 1) return b;
        if (x % 2 == 0) return fast_pow_mod (b * b % mod, x / 2, mod) % mod;

        return b * fast_pow_mod (b * b % mod, x / 2, mod) % mod;
    }

    public static long choose (long n, long k) {
        k = Math.min (k, n - k);
        long val = 1;

        for (int i = 0; i < k; ++i)
            val = val * (n - i) / (i + 1);

        return val;
    }

    public static long permute (int n, int k) {
        if (n < k) return 0;
        long val = 1;

        for (int i = 0; i < k; ++i)
            val = (val * (n - i));

        return val;
    }

}