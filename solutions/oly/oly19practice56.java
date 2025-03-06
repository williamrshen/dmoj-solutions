import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int m = ri(), n = ri(), u = ri(), f = ri(), d = ri();
        char[] h = readLine().toCharArray();
        int ans = 0;
        int out = 0;
        for (int i = 0; i < n; i ++) {
            if (ans > m) {
                out = i; break;
            }
            if (h[i] == 'u' || h[i] == 'd') {
                ans += u + d;
            }
            else ans += f + f;
            if (ans > m) {
                out = i; break;
            }
        }
        System.out.println(out);
    }




    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long rl () throws IOException {
        return Long.parseLong(next());
    }
    static int ri () throws IOException {
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