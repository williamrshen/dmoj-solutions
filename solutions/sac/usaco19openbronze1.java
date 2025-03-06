import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static boolean[] prime;
    public static void main(String[] args) throws IOException {
        char[][] m = new char[10][10];
        int sr = 0, sc = 0, er = 0, ec = 0;
        for (int i = 0; i < 10; i ++) {
            m[i] = readLine().toCharArray();
        }
        for (int i = 0; i < 10; i ++) {
            for (int j = 0; j < 10; j ++) {
                if (m[i][j] == 'L') {
                    sr = i; sc = j;
                }
                if (m[i][j] == 'B') {
                    er = i; ec = j;
                }
            }
        }
        int[][] move = {{1,0},{-1,0},{0,1},{0,-1}};
        Queue<p> q = new LinkedList<>(); q.add(new p(sr, sc));
        int[][] d = new int[10][10]; d[sr][sc] = 0;
        boolean[][] v = new boolean[10][20]; v[sr][sc] = true;
        while (!q.isEmpty()) {
            p c = q.poll();
            int cr = c.r;
            int cc = c.c;
            for (int i = 0; i < 4; i ++) {
                int nr = cr + move[i][0];
                int nc = cc + move[i][1];
                if (nr > 9 || nr < 0 || nc > 9 || nc < 0 || m[nr][nc] =='R' || v[nr][nc]) continue;
                v[nr][nc] = true;
                d[nr][nc] = d[cr][cc] + 1;
                q.add(new p(nr, nc));
                if (d[er][ec] > 0) {
                    System.out.println(d[er][ec] - 1);
                    return;
                }
            }
        }
        System.out.println(d[er][ec] - 1);
    }

    static class p {
        int r, c;
        public p (int a, int b) {
            r = a; c = b;
        }
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
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
}