import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt();
        int m = readInt();
        int in [] = new int [n + 1];
        List<Integer> adj[] = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList();
        for (int i = 1; i <= m; i ++) {
            int u = readInt();
            int v = readInt();
            adj[u].add(v);
            in [v] ++;
        }
        Queue<Integer> q = new LinkedList();
        int dp[] = new int [n + 1];
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (in[i] == 0) {
                q.add(i);
                dp[i] = 0;
            }
        }
            while (!q.isEmpty()) {
                int u = q.poll();
                ans = Math.max(ans, dp[u]);
                for (int v: adj[u]) {
                    dp[v] = Math.max(dp[v], dp[u] + 1);
                    if (--in[v] == 0) {
                        q.add(v);
                    }
                }
            }
            System.out.println(ans);

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