import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static boolean[][] adj;
    static int[] one;
    static int[] two;
    public static void main(String[] args) throws IOException {

        int n = readInt(), m = readInt();
        adj = new boolean[n + 1][n + 1];
        one = new int[m + 1];
        two = new int[m + 1];
        for (int i = 1 ; i <= m; i ++) {
            int a = readInt(), b = readInt();
            one[i] = a;
            two[i] = b;
            adj[a][b] = true;
        }
        for (int i = 1; i <= m; i ++) {
            System.out.println(bfs(i, n) ? "YES" : "NO");
        }
        
    }

    static boolean bfs (int i, int n) {
        adj[one[i]][two[i]] = false;
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[n + 1];
        v[1] = true;
        q.add(1);
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int x = 1; x <= n; x ++) {
                if (!v[x] && adj[c][x]) {
                    q.add(x);
                    v[x] = true;
                }
            }
        }
        adj[one[i]][two[i]] = true;
        if (v[n]) return true;
        else return false;
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}