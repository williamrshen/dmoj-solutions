import sun.security.provider.certpath.AdjacencyList;

import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int R = readInt();
        int C = readInt();
        int[][] a = new int[R + 1][C + 1];
        int max = (int)1e6;
        List<Integer>[] adj = new ArrayList[max + 1];
        for (int i = 1; i < adj.length; i ++) adj[i] = new ArrayList<>();
        for (int i = 1; i <= R; i ++) {
            for (int j = 1; j <= C; j ++) {
                a[i][j] = readInt();
                adj[i * j].add(a[i][j]);
            }
        }
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[max + 1];
        q.add(1);
        v[1] = true;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                }
            }
            if (v[R * C]) {
                System.out.println("yes");
                return;
            }
        }
        System.out.println("no");

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