import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        long n = readLong(), a[] = new long[(int)n];
        long g = readLong(); a[0] = g;
        for (int i = 1; i < n; i ++) { a[i] = readLong(); g = gcd(g, a[i]); }
        long out = solve(g);
        System.out.println(out == 1 ? "DNE" : out);
//        System.out.println(solve(31950));
    }
    static long gcd(long a, long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static long solve (long x) {
        long ans = 0;
        for (int i = 2; i < Math.sqrt(x); i ++) {
            while (x % i == 0) {
                x /= i;
                ans = Math.max(i, ans);
            }
        }
        return Math.max(x, ans);
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
}