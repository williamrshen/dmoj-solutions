import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt(), m = readInt(), t = readInt();
        List<Integer>[] adj = new List[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i ++) {
            int x = readInt(), y = readInt();
            adj[x].add(y);
        }
        int[][] ans = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i ++) Arrays.fill(ans[i], -1);
        for (int i = 1; i <= n; i ++) {
            Queue<Integer> q = new LinkedList<>(); q.add(i); ans[i][i] = 0;
            while (!q.isEmpty()) {
                int c = q.poll();
                for (int x : adj[c]) {
                    if (ans[i][x] == -1) {
                        q.add(x);
                        ans[i][x] = ans[i][c] + 1;
                    }
                }
            }
        }
        int q = readInt();
        for (int i = 0; i < q; i ++) {
            int x = readInt(), y = readInt();
            if (ans[x][y] < 0) System.out.println("Not enough hallways!");
            else System.out.println(ans[x][y] * t);
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