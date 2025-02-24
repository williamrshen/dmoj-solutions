import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = ri(), m = ri(); par = new int[n + 1];
        for (int i = 0; i <= n; i ++) par[i] = i;
        char[] s = readLine().toCharArray();
        for (int i = 1; i < n; i ++) {
            int x = ri() - 1, y = ri() - 1;
            if (s[x] == s[y]) par[find(x)] = find(y);
        }
        for (int i = 0; i < m; i ++) {
            int x = ri() - 1, y = ri() - 1;
            char w = readCharacter();
            if (s[x] != w && s[y] != w && find(x) == find(y)) System.out.print(0);
            else System.out.print(1);
        }
        System.out.println();
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