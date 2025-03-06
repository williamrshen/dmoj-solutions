import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, r, c;
    static int[][] plan;
    public static void main(String[] args) throws IOException {

        n = readInt(); r = readInt(); c = readInt();
        plan = new int[r][c];
        for (int i = 0; i < r; i ++) {
            char[] l = readLine().toCharArray();
            for (int j = 0; j < c; j ++) {
                if (l[j] == 'I') plan[i][j] = -1;
                else plan[i][j] = 0;
            }
        }

        int num = 1;
        for (int i = 0; i < r; i ++) {
          for (int j = 0; j < c; j ++) {
            if (plan[i][j] == 0) {
              fill(i, j, num);
              num ++;
            }
          }
        }

        int[] size = new int[1000];
        for (int i = 0; i < r; i ++) {
          for (int j = 0; j < c; j ++) {
            if (plan[i][j] > 0) {
              size[plan[i][j]] ++;
            }
          }
        }
        // for (int i = 0; i <= 6; i ++) {
        //   System.out.println(size[i]);
        // }
        // System.out.println();

        int ans = 0;
        while (n > 0) {
          int max = 0;
          for (int i = 0; i < 1000; i ++) {
            if (size[i] > size[max]) max = i;
          }
          if (size[max] > 0 && size[max] <= n) {
                n -= size[max];
                size[max] = -1;
                ans ++;
          }
          else break;
        }
        if (ans == 1) {
            System.out.println(ans + " room, " + n + " square metre(s) left over");
        }
        else System.out.println(ans + " rooms, " + n + " square metre(s) left over");

        
    }

    static void fill (int i, int j, int k) {
      if (i >= 0 && i < r && j >= 0 && j < c && plan[i][j] == 0) {
        plan[i][j] = k;
        fill(i - 1, j, k); fill(i + 1, j, k); fill(i, j - 1, k); fill(i, j + 1, k);
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