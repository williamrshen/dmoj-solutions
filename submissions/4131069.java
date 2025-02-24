import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int m = ri(), n = ri();
        char map[][] = new char[n][m];
        for (int i = 0; i < n; i ++) {
            map[i] = readLine().toCharArray();
        }
        TreeSet<Character> out = new TreeSet<>();
        pair s = new pair(0, 0);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (map[i][j] == '1') {
                    s = new pair(i, j);
                }
            }
        }
        Queue<pair> q = new LinkedList<>(); q.add(s);
        boolean v[][] = new boolean[n][m]; v[s.f][s.s] = true;
        while (!q.isEmpty()) {
            int cr = q.peek().f;
            int cc = q.peek().s;
            q.poll();
            for (int i = 0; i < 4; i ++) {
                int nr = cr + move[i][0];
                int nc = cc + move[i][1];
                if (nr >= n || nr < 0 || nc >= m || nc < 0 || v[nr][nc] || map[nr][nc] == '#') continue;
                q.add(new pair(nr, nc));
                v[nr][nc] = true;
                if (Character.isDigit(map[nr][nc])) out.add(map[nr][nc]);
            }
        }
        System.out.print(1 + " ");
        for (Character x : out) {
            System.out.print(" " + x);
        }
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long rl () throws IOException {
        return Long.parseLong(next());
    }
    static int ri () throws IOException {
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

    static class pair implements Comparable<pair> {
        int f, s;
        public pair (int a, int b) { f = a; s = b; }
        public int compareTo (pair o) {
            return this.f - o.f;
        }
    }

    static int move[][] = {{1,0},{-1,0},{0,1},{0,-1}};
}