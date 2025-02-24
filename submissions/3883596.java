import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] v;
    static int[][] memo;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int x = readInt(), n = readInt(), a = x;
        for (int i = 0; i < n; i ++) a += (x - readInt());
        System.out.print(a);
    }
    public static int dp (int l, int r, boolean t) {
        if (l == r) {
            if (t) return memo[l][r] = v[l];
            else return memo[l][r] = -v[l];
        }
        if (memo[l][r] != -1) return memo[l][r];

        int left = dp(l + 1, r, !t), right = dp(l, r - 1, !t);
        if (t) return memo[l][r] = Math.max(left + v[l], right + v[r]);
        else return memo[l][r] = Math.min(left - v[l], right - v[r]);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}