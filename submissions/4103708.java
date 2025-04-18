import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = ri(), m = ri(); par = new int[n + 1];
        for (int i = 0; i <= n; i ++) par[i] = i;
        edge[] e = new edge[m + 1];
        for (int i = 1; i <= m; i ++) {
            e[i] = new edge(ri(), ri(), i);
        }
        int c = 1;
        List<Integer> ans = new ArrayList<>();
        while (ans.size() < n - 1) {
            edge cur = e[c];
            if (find(cur.e) != find(cur.b)) {
                merge(cur.e, cur.b);
                ans.add(c);
            }
            c ++;
            if (c > m) break;
        }
        if (ans.size() != n - 1) System.out.println("Disconnected Graph");
        else {
            for (int x : ans) System.out.println(x);
        }
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

    static int[][] move = {{1,0},{-1,0},{0,1},{0,-1}};

    static class pair implements Comparable<pair> {
        int f, s;
        public pair (int a, int b) { f = a; s = b; }
        public int compareTo (pair o) {
            return o.f - this.f;
        }
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