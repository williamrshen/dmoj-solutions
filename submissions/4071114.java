import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), q = readInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        int[] p = new int[n + 1];
        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i ++) { a[i] = i; p[i] = i; }
        for (int i = 0; i < q; i ++) {
            char o = readCharacter();
            if (o == 'E') {
                int x = readInt(), y = readInt();
                p[a[x]] = y; p[a[y]] = x;
                int t = a[x]; a[x] = a[y]; a[y] = t;
            }
            else if (o == 'B') {
                int x = readInt(), y = readInt();
                a[p[x]] = y; a[p[y]] = x;
                int t = p[x]; p[x] = p[y]; p[y] = t;
            }
            else {
                for (int j = 1; j <= n; j ++) {
                    b[j] = readInt();
                    ans[a[j]] = b[j];
                }
                for (int j = 1; j <= n; j ++) System.out.print(ans[j] + (j == n ? "\n" : " "));
            }
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