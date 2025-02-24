import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), ans = 0, one[] = new int[n + 1], two[] = new int[n + 1];
        one[0] = 0;
        for (int i = 1; i <= n; i ++) one[i] = one[i - 1] + readInt();
        two[0] = 0;
        for (int i = 1; i <= n; i ++) two[i] = two[i - 1] + readInt();
        for (int i = 1; i <= n; i ++) {
            if (one[i] == two[i]) ans = i;
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