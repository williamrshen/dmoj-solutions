import java.io.*;
import java.util.*;
public class Main {

    static boolean[][] adj = new boolean[26][26];
    static int count;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        List<String> l = new ArrayList<>();
        while (true) {

            String s = next();
            char[] in = s.toCharArray();
            if (in[1] == '*') break;
            l.add(s);
            adj[in[0] - 'A'][in[1] - 'A'] = adj[in[1] - 'A'][in[0] - 'A'] = true;

        }

        for (String s : l) {

            int a = s.charAt(0) - 'A';
            int b = s.charAt(1) - 'A';
            adj[a][b] = adj[b][a] = false;
            if (!bfs(0, 1)) {
                System.out.println(s);
                count ++;
            }
            adj[a][b] = adj[b][a] = true;

        }
        System.out.println("There are " + count + " disconnecting roads.");

    }

    static boolean bfs (int s, int e) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[26];
        q.add(s);
        v[s] = true;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int next = 0; next < 26; next ++) {
                if (adj[c][next] && !v[next]) {
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}