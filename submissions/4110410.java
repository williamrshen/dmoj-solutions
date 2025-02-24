import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = ri(), ans = 0;
        int[] w = new int[n];
        for (int i = 0; i < n; i ++) w[i] = ri();
        Arrays.sort(w);
        for (int i = n - 1; i >= 0; i --) {
            if (w[i] < ans) break;
            ans ++;
        }
        System.out.println(ans);
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

    static int[][] move = {{1,0},{-1,0},{0,1},{0,-1}};

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