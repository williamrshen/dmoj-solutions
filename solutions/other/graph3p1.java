import java.io.*;
import java.util.*;
public class Main {

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int m = readInt();
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 1; i <= m; i ++) {
            int a = readInt(), b = readInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        int k = readInt();
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[n + 1];
        int[] d = new int[n + 1];
        int max = 0;
        for (int i = 1; i <= k; i ++) {
            int x = readInt();
            q.add(x);
            v[x] = true;
        }
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                    d[next] = d[c] + 1;
                    if (d[next] > max) max = d[next];
                }
            }
        }
        System.out.println(max);
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