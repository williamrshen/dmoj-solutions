import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        long[] ans = new long[n + 1];
        long ok = 0;
        for (int i = 2; i <= n; i ++) {
            if (i == 2) {
                System.out.println("? 1 2"); System.out.flush();
                long x = readLong();
                System.out.println("? 1 2"); System.out.flush();
                long xx = readLong();
                ans[2] = xx / 2; ok = ans[2] + x; ans[1] = 2 * ok;
            }
            else {
                System.out.println("? 1 " + i); System.out.flush();
                long x = readLong(); // ans[1] - i
                long y = ans[1] - x;
                ans[1] += y;
                ans[i] = y;
            }
        }
        System.out.print("! " + ok);
        for (int i = 2; i <= n; i ++) System.out.print(" " + ans[i]);
        System.out.println(); System.out.flush();
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