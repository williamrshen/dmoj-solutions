import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int[] p = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            p[i] = readInt();
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int t = 0;
                for (int k = i; k <= j; k ++) {
                    t += p[k];
                }
                boolean a = false;
                for (int k = i; k <= j; k ++) {
                    if (p[k] * (j - i + 1) == t) {
                        a = true;
                    }
                }
                if (a) ans ++;
            }
        }
        System.out.println(ans);
    }

    static long gcd (long a, long b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}