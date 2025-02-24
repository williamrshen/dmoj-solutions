import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] par;
    static int[] size;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        while (n != 0) {

            par = new int[n + 1];
            size = new int[n + 1];
            for (int i = 0; i <= n; i ++) { par[i] = i; size[i] = 1; }
            for (int i = 0; i < n; i ++) {
                int u = readInt(), v = readInt();
                merge(u, v);
            }
//            int[] mm = new int[m + 1];
//            for (int i = 1; i <= m; i ++) {
//                mm[i] = dfs(i, i);
//            }
            int l = 1;
            for (int i = 1; i <= n; i ++) {
                l = lcm(l, size[i]);
            }
            System.out.println(l);
            n = readInt();
        }

    }

//    static int dfs(int cur, int s) {
//        if (ring[cur].get(0) == s) return 1;
//        return dfs(ring[cur].get(0), s) + 1;
//    }

    static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static int lcm (int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    static void merge (int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            par[x] = y;
            size[y] += size[x];
            size[x] = 1;
        }
    }

    static int find (int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
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