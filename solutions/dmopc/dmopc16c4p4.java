import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int mn = 100005, mq = 100005, sq = 320;
    static int n, q;
    static int[] a = new int[mn];
    static int[] out = new int[mq];
    static int[] ref = new int[mn];
    public static void main(String[] args) throws IOException {
        n = ri();
        for (int i = 1; i <= n; i ++) a[i] = ri();
        q = ri();
        ArrayList<query> qs = new ArrayList<>();
        for (int i = 1; i <= q; i ++) {
            int l = ri(), r = ri();
            qs.add(new query(l, r, i));
        }
        Collections.sort(qs, new cmp());
        int l = 1, r = 0, ans = 0;
        for (query Q : qs) {
            while (r < Q.r) {
                r ++;
                if (ref[a[r]] % 2 == 1) ans ++;
                if (ref[a[r]] % 2 == 0 && ref[a[r]] != 0) ans --;
                ref[a[r]] ++;
            }
            while (l > Q.l) {
                l --;
                if (ref[a[l]] % 2 == 1) ans ++;
                if (ref[a[l]] % 2 == 0 && ref[a[l]] != 0) ans --;
                ref[a[l]] ++;         
            }
            while (r > Q.r) {
                ref[a[r]] --;
                if (ref[a[r]] % 2 == 1) ans --;
                if (ref[a[r]] % 2 == 0 && ref[a[r]] != 0) ans ++;
                r --;
            }
            while (l < Q.l) {
                ref[a[l]] --;
                if (ref[a[l]] % 2 == 1) ans --;
                if (ref[a[l]] % 2 == 0 && ref[a[l]] != 0) ans ++;
                l ++;
            }
            out[Q.i] = ans;
        }
        for (int i = 1; i <= q; i ++) System.out.println(out[i]);
    }

    static class cmp implements Comparator<query> {
        public int compare(query a, query b) {
            if (a.l / sq != b.l / sq) {
                return a.l / sq - b.l / sq;
            }
            else return a.r - b.r;
        }
    }
    static class query {
        int l, r, i;
        public query (int a, int b, int c) {
            l = a; r = b; i = c;
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