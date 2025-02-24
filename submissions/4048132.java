import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static List<Integer>[] ring;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        while (n != 0) {

            ring = new List[n + 1];
            int m = 0;
            for (int i = 1; i <= n; i ++) ring[i] = new ArrayList<>();
            for (int i = 0; i < n; i ++) {
                int u = readInt(), v = readInt();
                m = Math.max(Math.max(m, u), v);
                ring[u].add(v);
            }
            int[] mm = new int[m + 1];
            for (int i = 1; i <= m; i ++) {
                mm[i] = dfs(i, i);
            }
            int l = 1;
            for (int i = 1; i <= m; i ++) {
                l = lcm(l, mm[i]);
            }
            System.out.println(l);
            n = readInt();
        }

    }

    static int dfs(int cur, int s) {
        if (ring[cur].get(0) == s) return 1;
        return dfs(ring[cur].get(0), s) + 1;
    }

    static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static int lcm (int a, int b) {
        return (a / gcd(a, b)) * b;
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