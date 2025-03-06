import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int m = readInt();
        int a = readInt();
        int b = readInt();
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 1; i <= m; i ++) {
            int x = readInt();
            int y = readInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        Queue<Integer> q = new PriorityQueue<>();
        boolean[] v = new boolean[n + 1];
        int[] dis = new int[n + 1];
        q.add(a);
        v[a] = true;
        dis[a] = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int next : adj[c]) {
                if (!v[next]) {
                    q.add(next);
                    v[next] = true;
                    dis[next] = dis[c] + 1;
                }
            }
        }
        if (!v[b]) System.out.println("NO SHAHIR!");
        else System.out.println("GO SHAHIR!");
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