import sun.security.provider.certpath.AdjacencyList;

import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt(), m = readInt();
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 1; i <= m; i ++) {
            int a = readInt(), b = readInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        int w = readInt();
        int[] d = new int[n + 1];
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[n + 1];
        for (int i = 1; i <= w; i ++) {
            int x = readInt();
            q.add(x);
            v[x] = true;
        }
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : adj[cur]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                    d[next] = d[cur] + 4;
                }
            }
        }
        Arrays.fill(v, false);
        int[] hd = new int[n + 1];
        q.add(1);
        v[1] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : adj[cur]) {
                if (!v[next] && hd[cur] + 1 < d[next]) {
                    q.add(next);
                    v[next] = true;
                    hd[next] = hd[cur] + 1;
                }
            }
        }
        if (v[n]) System.out.println(hd[n]);
        else System.out.println("sacrifice bobhob314");

    }




    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}