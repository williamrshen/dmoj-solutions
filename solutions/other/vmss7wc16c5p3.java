import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i ++) {
            int x = readInt(), y = readInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        Queue<Integer> q = new LinkedList<>();
        int[] d = new int[n + 1];
        Arrays.fill(d, -1);
        d[1] = 0;
        q.add(1);
        int max = -1, maxi = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int x : adj[c]) {
                if (d[x] == -1) {
                    q.add(x);
                    d[x] = d[c] + 1;
                    if (d[x] > max) { max = d[x]; maxi = x; }
                }
            }
        }

        q.add(maxi);
        Arrays.fill(d, -1);
        d[maxi] = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int x : adj[c]) {
                if (d[x] == -1) {
                    q.add(x);
                    d[x] = d[c] + 1;
                    if (d[x] > max) max = d[x];
                }
            }
        }
        System.out.println(max);
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