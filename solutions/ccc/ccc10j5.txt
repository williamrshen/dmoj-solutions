import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int startx = readInt();
        int starty = readInt();
        int endx = readInt();
        int endy = readInt();
        Queue<coord> q = new LinkedList<>();
        boolean v[][] = new boolean[9][9];
        int d[][] = new int[9][9];
        int[][] s = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        q.add(new coord(startx, starty));
        v[startx][starty] = true;
        d[startx][starty] = 0;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int k = 0; k < 8; k ++) {
                int nx = x + s[k][0];
                int ny = y + s[k][1];
                if (nx < 1 || nx > 8 || ny < 1 || ny > 8 || v[nx][ny]) continue;
                q.add(new coord(nx, ny));
                v[nx][ny] = true;
                d[nx][ny] = d[x][y] + 1;
            }
        }
        System.out.println(d[endx][endy]);
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