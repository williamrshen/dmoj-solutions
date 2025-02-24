import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int h = readInt();
        int[][] f = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                f[i][j] = readInt();
            }
        }
        Queue<coord> q = new LinkedList<>();
        boolean v[][] = new boolean[n + 1][n + 1];
        int[][] move = {{-1,0},{1,0},{0,-1},{0,1}};
        q.add(new coord(1, 1));
        v[1][1] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int k = 0; k < move.length; k ++) {
                int nx = x + move[k][0];
                int ny = y + move[k][1];
                if (nx < 1 || nx > n || ny < 1 || ny > n || Math.abs(f[x][y] - f[nx][ny]) > h || v[nx][ny]) continue;
                q.add(new coord(nx, ny));
                v[nx][ny] = true;
            }
        }
        System.out.println(v[n][n]? "yes" : "no");
    }

    static class coord {
        int x;
        int y;
        coord(int xx, int yy) {
            x = xx;
            y = yy;
        }
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