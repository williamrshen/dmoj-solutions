import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        long n = readLong();
        long k = readLong();
        long ans = 0;
        long p = 1;
        while (p < k && p < n) {
            p += p;
            ans ++;
        }
        ans += (n - p + k - 1) / k;
        System.out.println(ans);
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
    static long readLong () throws IOException {
		return Long.parseLong(next());
	}
}