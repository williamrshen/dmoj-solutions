import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int h = ri(), w = ri();
        char[][] m = new char[h][w];
        long[][] dp = new long[h][w];
        for (int i = 0; i < h; i ++) {
            m[i] = readLine().toCharArray();
        }
        dp[0][0] = 1;
        for (int i = 1; i < h; i ++) {
            if (m[i][0] == '#') dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
            dp[i][0] %= 1000000007;
        }
        for (int i = 1; i < w; i ++) {
            if (m[0][i] == '#') dp[0][i] = 0;
            else dp[0][i] = dp[0][i - 1];
            dp[0][i] %= 1000000007;
        }
        for (int i = 1; i < h; i ++) {
            for (int j = 1; j < w; j ++) {
                if (m[i][j] == '#') dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
        System.out.println(dp[h - 1][w - 1] % 1000000007);
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long rl () throws IOException {
        return Long.parseLong(next());
    }
    static int ri () throws IOException {
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

    static int[] par, rank;

    static int find (int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    static void merge2 (int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (rank[x] >= rank[y]) {
            rank[x] += rank[y];
            par[y] = x;
        }
        else {
            rank[y] += rank[x];
            par[x] = y;
        }
    }

    static class pair implements Comparable<pair> {
        int f, s;
        public pair (int a, int b) { f = a; s = b; }
        public int compareTo (pair o) {
            return this.f - o.f;
        }
    }

    static long pow( long x, long n) {
        if(n == 0) return 1;
        long t = pow(x, n / 2);
        t = t * t;
        if(n % 2 == 0) return t;
        return t * x;
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
}