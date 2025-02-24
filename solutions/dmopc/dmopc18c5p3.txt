import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        long a[] = new long[n];
        long ans = 0;
        long m = readLong(), t[] = new long[n];
        a[0] = readLong(); t[0] = a[0];
        for (int i = 1; i < n; i ++) {
            a[i] = readLong();
            t[i] = t[i - 1] + a[i];
        }
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (t[r] - t[l] + a[l] >= m || t[l] - t[r] + a[r] >= m) r ++;
            else {
                ans = Math.max(ans, Math.abs(r - l) + 1);
                l ++;
            }
        }
        System.out.println(ans);
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