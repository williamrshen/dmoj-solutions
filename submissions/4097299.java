import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int mn = 200005, sq = 449;
    static int n, q, c = 1;
    static int[] arr = new int[mn], block = new int[mn];
    static int[][] ref = new int[sq][mn];
    public static void main(String[] args) throws IOException {
        n = readInt(); q = readInt();
        for (int i = 1; i <= n; i ++) arr[i] = readInt();
        for (int i = 1; i <= n; i += sq) {
            for (int j = i; j < Math.min(n + 1, i + sq); j ++)  {
                block[j] = c;
                for (int k = 1; k * k <= arr[j]; k ++) {
                    if (arr[j] % k == 0) {
                        ref[c][k] ++;
                        if (k != arr[j] / k) ref[c][arr[j] / k] ++;
                    }
                }
            }
            c ++;
        }
        for (int j = 0; j < q; j ++) {
            int o = readInt();
            if (o == 1) {
                int l = readInt(), r = readInt(), x = readInt();
                int nl = block[l], nr = block[r], ans = 0;
                if (nl == nr) {
                    for (int i = l; i <= r; i ++) {
                        if (arr[i] % x == 0) ans ++;
                    }
                }
                else {
                    while (block[l] == nl) {
                        if (arr[l] % x == 0) ans ++;
                        l ++;
                    }
                    while (block[r] == nr) {
                        if (arr[r] % x == 0) ans ++;
                        r --;
                    }
                    for (int i = nl + 1; i < nr; i ++) ans += ref[i][x];
                }
                System.out.println(ans);
            }
            else {
                int u = readInt(), v = readInt();
                c = block[u];
                for (int k = 1; k * k <= arr[u]; k ++) {
                    if (arr[u] % k == 0) {
                        ref[c][k] --;
                        if (k != arr[u] / k) ref[c][arr[u] / k] --;
                    }
                }
                arr[u] = v;
                for (int k = 1; k * k <= arr[u]; k ++) {
                    if (arr[u] % k == 0) {
                        ref[c][k] ++;
                        if (k != arr[u] / k) ref[c][arr[u] / k] ++;
                    }
                }
            }
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

    static int[] par;

    static int find (int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    static void merge (int x, int y) {
        par[find(y)] = par[find(x)];
    }

    static class edge implements Comparable<edge> {
        int b, e, w;
        public edge (int b, int e, int w){
            this.b = b; this.e = e; this.w = w;
        }
        public int compareTo (edge o) {
            return o.w - this.w;
        }
    }

    static int[][] move = {{1,0},{-1,0},{0,1},{0,-1}};

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