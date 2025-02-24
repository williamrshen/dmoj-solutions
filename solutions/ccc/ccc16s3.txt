import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, nn, d, f, s;
    static List<Integer>[] adj;
    static boolean[] pho;
    public static void main(String[] args) throws IOException {
        n = readInt(); m = readInt(); s = 0; f = 0;
        pho = new boolean[n]; adj = new List[n];
        for (int i = 0; i < n; i ++) adj[i] = new ArrayList();
        for (int i = 1; i <= m; i ++) { s = readInt(); pho[s] = true; }
        for (int i = 1; i < n; i ++) {
            int a = readInt(), b = readInt();
            adj[a].add(b); adj[b].add(a);
        }
        dfs (s, -1);
        d = 0; dfss(s, -1, 0);
        d = 0; dfss(f, -1, 0);
        System.out.println(2 * (nn - 1) - d);
    }

    static void dfs (int cur, int pre) {
        for (int x : adj[cur]) {
            if (x != pre) {
                dfs(x, cur);
                if (pho[x]) pho[cur] = true;
            }
        }
        if (pho[cur]) nn ++;
    }

    static void dfss (int cur, int pre, int dis) {
        if (dis > d) {
            d = dis; f = cur;
        }
        for (int x : adj[cur]) {
            if (x != pre && pho[x]) dfss(x, cur, dis + 1);
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
}