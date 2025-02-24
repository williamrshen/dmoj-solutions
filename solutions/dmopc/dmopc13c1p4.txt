import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[][] s = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int k = 0; k < n; k ++) {
            int c = readInt();
            int r = readInt();
            coord start = new coord(0, 0), end = new coord(0, 0);
            char[][] map = new char[r][c];
            for (int i = 0; i < r; i ++) {
                map[i] = br.readLine().toCharArray();
                for (int j = 0; j < c; j ++) {
                    if (map[i][j] == 'C') start = new coord(i , j);
                    if (map[i][j] == 'W') end = new coord(i, j);
                }
            }
            Queue<coord> q = new LinkedList<>();
            int[][] d = new int[r][c];
            boolean[][] v = new boolean[r][c];
            q.add(start);
            v[start.x][start.y] = true;
            while (!q.isEmpty()) {
                int curx = q.peek().x;
                int cury = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i ++) {
                    int nr = curx + s[i][0];
                    int nc = cury + s[i][1];
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c || v[nr][nc] || map[nr][nc] == 'X') continue;
                    q.add(new coord(nr, nc));
                    v[nr][nc] = true;
                    d[nr][nc] = d[curx][cury] + 1;
                }
            }
            if (v[end.x][end.y] && d[end.x][end.y] < 60) System.out.println(d[end.x][end.y]);
            else System.out.println("#notworth");
        }

    }

    static class coord {
        int x;
        int y;
        coord (int xx, int yy) {
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}