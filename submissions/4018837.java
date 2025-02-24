import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    Set<String> set = new HashSet<>();
    char[] s;
    public static void main(String[] args) throws IOException {
        
        int m = readInt(), n = readInt();
        int sr = readInt() - 1, sc = readInt() - 1;
        int er = readInt() - 1, ec = readInt() - 1;
        char[][] map = new char[m][n];
        for (int i = 0; i < m; i ++) {
          map[i] = readLine().toCharArray();
        }
        int[][] move = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{1,0},{-1,0},{0,1},{0,-1}};
        Queue<point> q = new LinkedList<>();
        int[][] d = new int[m][n];
        for (int i = 0; i < m; i ++) {
          for (int j = 0; j < n; j ++) {
            d[i][j] = -1;
          }
        }
        d[sr][sc] = 0;
        q.add(new point(sr, sc));
        while (!q.isEmpty()) {
          int r = q.peek().r;
          int c = q.peek().c;
          q.poll();
          for (int i = 0; i < 12; i ++) {
            int nr = r + move[i][0];
            int nc = c + move[i][1];
            if (nr < 0 || nr > m - 1 || nc < 0 || nc > n - 1 || map[nr][nc] == '#' || d[nr][nc] != -1) continue;
            q.add(new point(nr, nc));
            d[nr][nc] = d[r][c] + 1;
            if (nr == er && nc == ec) {
              System.out.println(d[nr][nc]);
              return;
            }
          }
        }
        System.out.println(-1);
      
       
    }
    
    static class point {
      int r;
      int c;
      public point (int y, int x) {
        r = y;
        c = x;
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