import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = ri(), k = ri(), j = ri();
        int[] holes = new int[1000005], moves = new int[1005], dp = new int[1000005];
        for (int i = 0; i < k; i ++) {
            holes[i] = ri();
        }
        for (int i = 0; i < j; i ++) {
            moves[i] = ri();
        }
        Arrays.fill(dp, 999999);
        dp[0] = 0;
        for (int i = 0; i < k; i ++) {
            dp[holes[i]] = -1;
        }
        for (int i = 0; i <= n; i ++) {
            for (int l = 0; l < j; l ++) {
                if (i - moves[l] >= 0) {
                    if (dp[i - moves[l]] == -1) continue;
                    dp[i] = Math.min(dp[i], dp[i - moves[l]] + 1);
                }
            }
        }
        if (dp[n] == 999999) System.out.println(-1);
        else System.out.println(dp[n]);
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