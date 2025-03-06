import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long memo[];
    public static void main(String[] args) throws IOException {
        int n = readInt();
        memo = new long[n + 5];
        System.out.println(f(n));
    }

    static long f (int n) {
        if (memo[n] != 0) return memo[n];
        if (n < 2) return 1;
        long ans = 1;
        for (int i = 1; i <= n / 2; i ++) {
            ans += f(n - 2 * i);
        }
        return memo[n] = ans;
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