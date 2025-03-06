import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int m = readInt(), n = readInt();
        int sr = readInt() - 1, sc = readInt() - 1;
        int er = readInt() - 1, ec = readInt() - 1;
        char[][] maze = new char[m][n];
        for (int i = 0; i < m; i ++) {
            maze[i] = readLine().toCharArray();
        }

//        bfs
        int[][] move = {{2,-1},{2,1},{-2,-1},{-2,1},{1,2},{-1,2},{1,-2},{-1,-2},{1,0},{-1,0},{0,-1},{0,1}};
        Queue<coord> q = new LinkedList<>();
        boolean[][] v = new boolean[m][n];
        int[][] d = new int[m][n];
        v[sr][sc] = true;
        d[sr][sc] = 0;
        q.add(new coord(sr, sc));
        while (!q.isEmpty()) {
            int row = q.peek().x;
            int col = q.peek().y;
            q.poll();
            for (int i = 0; i < 12; i ++) {
                int newrow = row + move[i][0];
                int newcol = col + move[i][1];
                if (newrow < 0 || newrow > m - 1 || newcol < 0 || newcol > n - 1 || v[newrow][newcol]) continue;
                if (maze[newrow][newcol] == '#') continue;
                q.add(new coord(newrow, newcol));
                v[newrow][newcol] = true;
                d[newrow][newcol] = d[row][col] + 1;
            }
            if (v[er][ec]) { System.out.println(d[er][ec]); return; };
        }
        System.out.println(-1);

    }

    static class coord {
        int x;
        int y;
        public coord (int a, int b) {
            x = a;
            y = b;
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