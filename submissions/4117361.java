import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] a;
    public static void main(String[] args) throws IOException {
        int t = ri();
        a = new int[t];
        for (int i = 0; i < t; i ++) a[i] = ri();
        print(t);
        boolean ok = true;
        while (ok) {
            ok = false;
            for (int i = 0; i < t - 1; i ++) {
                if (a[i] > a[i + 1]) {
                    int tm = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tm;
                    print(t);
                    ok = true;
                }
            }
        }
    }

    static void print (int t) {
        for (int i = 0; i < t - 1; i ++) System.out.print(a[i] + " ");
        System.out.println(a[t - 1]);
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