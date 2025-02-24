import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int r, c;
    static char[][] map;
    public static void main(String[] args) throws IOException {

          r = readInt(); c = readInt();
          int ans = 0;
          map = new char[r][c];
          for (int i = 0; i < r; i ++) {
            map[i] = readLine().toCharArray();
          }
          for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
              if (map[i][j] == 'M') {
                ans ++;
                fill(i, j);
              }
            }
          }
          System.out.println(ans);

    }
    static void fill (int i, int j) {
      if (i >= 0 && i < r && j >= 0 && j < c && map[i][j] != '#') {
        map[i][j] = '#';
        fill(i - 1, j); fill(i + 1, j); fill(i, j - 1); fill(i, j + 1);
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