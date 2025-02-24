import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt(), max = 0, e = 0;
        List<pair>[] adj = new List[n + 1];
        for (int i = 0; i <= n; i ++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            int a = readInt(), b = readInt(), c = readInt();
            adj[a].add(new pair(b, c));
            adj[b].add(new pair(a, c));
            e += c * 2;
        }

        Queue<Integer> q = new LinkedList<>(); q.add(0);
        int[] d = new int[n + 1]; Arrays.fill(d, -1); d[0] = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (pair x : adj[c]) {
                if (d[x.end] == -1) {
                    d[x.end] = d[c] + x.time;
                    if (d[x.end] > d[max]) max = x.end;
                    q.add(x.end);
                }
            }
        }
//        Arrays.fill(d, -1); d[max] = 0; q.add(max);
//        while (!q.isEmpty()) {
//            int c = q.poll();
//            for (pair x : adj[c]) {
//                if (d[x.end] == -1) {
//                    d[x.end] = d[c] + x.time;
//                    if (d[x.end] > d[max]) max = x.end;
//                    q.add(x.end);
//                }
//            }
//        }
        System.out.println(e - d[max]);
    }

    static class pair {
        int end, time;
        public pair (int a, int b) {
            end = a; time = b;
        }
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