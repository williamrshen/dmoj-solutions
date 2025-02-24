import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static boolean[][] v = new boolean[105][105];
    static List<Integer>[] adj = new List[105];
    public static void main(String[] args) throws IOException {
        int n = readInt();
        for (int i = 0; i < 105; i ++) adj[i] = new ArrayList<>();
        for (int i = 1; i < n; i ++) {
            int a = readInt(), b = readInt();
            adj[a].add(b);
        }
        for (int i = 1; i <= n; i ++) {
            search (i);
            v[i][i] = true;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (!v[i][j]) break;
                if (j == n) { System.out.println(i); return; }
            }
        }
        System.out.println(-1);
    }

    static void search (int s) {
        Queue<Integer> q = new LinkedList<>(); q.add(s);
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int x : adj[c]) {
                if (!v[x][s]) {
                    v[x][s] = true;
                    q.add(x);
                }
            }
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

// cool stuffs

    static long pow(long x, long n) {
        if(n == 0) return 1;
        long t = pow(x, n/2);
        t = t*t;
        if(n % 2 == 0) return t;
        return t*x;
    }

}