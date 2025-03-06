import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] p;
    public static void main(String[] args) throws IOException {

        int n = readInt(), q = readInt();
        p = new int[n + 1];
        for (int i = 1; i <= n; i ++) p[i] = i;
        long[] r = new long[n + 1];
        long[] s = new long[n + 1];
        Arrays.fill(s, 1);
        for (int i = 1; i <= n; i ++) {
              r[i] = readLong();
        }

        for (int i = 0; i < q; i ++) {
              int x = readInt();
              if (x == 1) {

                  int a = readInt(), b = readInt();
                  if (find(a) == find(b)) continue;
                  s[find(a)] += s[find(b)];
                  r[find(a)] += r[find(b)];
                  merge(a, b);
                  
              }
              else if (x == 2) {

                  int a = readInt();
                  System.out.println(s[find(a)]);

              }
              else {

                  int a = readInt();
                  System.out.println(r[find(a)]);

              }

        }

    }

    static int find (int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    
    static void merge (int x, int y) {
        x = find(x); y = find(y);
        p[y] = x;
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