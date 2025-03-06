import sun.security.provider.certpath.AdjacencyList;

import java.io.*;
import java.util.*;
public class Main {
    static int n;
    static int m;
    static List<Integer>[] adj;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        n = readInt();
        m = readInt();
        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 1; i < m + 1; i ++) {
            int x = readInt();
            int y = readInt();
            adj[x].add(y);
        }
        int p = readInt();
        int q = readInt();
        if (bfs(p , q)) System.out.println("yes");
        else if (bfs(q, p)) System.out.println("no");
        else System.out.println("unknown");
    }

    static boolean bfs (int s, int e) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[n + 1];
        q.add(s);
        v[s] = true;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                }
            }
            if (v[e]) return true;
        }
        return false;
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}