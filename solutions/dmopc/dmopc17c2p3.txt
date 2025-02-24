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
        for (int i = 1; i < n; i ++) {
            int x = readInt();
            int y = readInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[n + 1];
        int[] d = new int[n + 1];
        for (int i = 1; i <= m; i ++) {
            int x = readInt();
            q.add(x);
            v[x] = true;
        }
        while(!q.isEmpty()) {
            int c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                        q.add(next);
                        v[next] = true;
                        d[next] = d[c] + 1;
                }
            }
        }
        Arrays.fill(v, false);
        int[] p = new int[n + 1];
        int x = readInt();
        int y = readInt();
        q.add(x);
        v[x] = true;
        p[x] = -1;
        while(!q.isEmpty()) {
            int  c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                    p[next] = c;
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        int c = y;
        for ( ; c != -1; c = p[c]) ans = Math.min(ans, d[c]);
        System.out.println(ans);
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