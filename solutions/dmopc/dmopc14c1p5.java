import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int r = readInt(), c = readInt();
        int sr = readInt(), sc = readInt();
        int er = readInt(), ec = readInt();
        char[][] map = new char[r][c];
        for (int i = 0; i < r; i ++) {
            map[i] = readLine().toCharArray();
        }
        int t = readInt();
        for (int i = 0; i < t; i ++) {
            int x = readInt(), y = readInt();
            map[x][y] = 'T';
        }
        int[][] move = {{1,0},{-1,0},{0,1},{0,-1}};
        int tt = Integer.MAX_VALUE;
        if (map[sr][sc] == 'T') tt = 0;
        Queue<point> q = new LinkedList<>();
        int[][] d = new int[r][c];
        for (int i = 0; i < r; i ++) Arrays.fill(d[i], -1);
        d[sr][sc] = 0;
        q.add(new point(sr, sc));
        while (!q.isEmpty()) {
            int rr = q.peek().a;
            int cc = q.peek().b;
            q.poll();
            for (int i = 0; i < 4; i ++) {
                int nr = rr + move[i][0];
                int nc = cc + move[i][1];
                if (nr < 0 || nr >= r || nc < 0 || nc >= c || map[nr][nc] == 'X' || d[nr][nc] != -1) continue;
                q.add(new point(nr, nc));
                d[nr][nc] = d[rr][cc] + 1;
                if (map[nr][nc] == 'T' && d[nr][nc] < tt) tt = d[nr][nc];
            }
        }
        if (d[er][ec] - tt <= 0) System.out.println(0);
        else System.out.println(d[er][ec] - tt);

        
    }

    static class point {
        int a, b;
        public point (int x, int y) {
            a = x; b = y;
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