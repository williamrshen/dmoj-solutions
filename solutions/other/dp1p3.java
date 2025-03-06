import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), ans = 0, arr[] = new int[n];
        for (int i = 0; i < n; i ++) arr[i] = readInt();
        int[] lis = new int[n]; Arrays.fill(lis, 1);
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                    ans = Math.max(ans, lis[j]);
                }
            }
        }
        System.out.println(ans + 1);
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

    static class pair implements Comparable<pair> {
        int f, s;
        public pair (int a, int b) { f = a; s = b; }
        public int compareTo (pair o) {
            return this.f - o.f;
        }
    }

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