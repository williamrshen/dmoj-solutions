import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[] ok = new int[n];
        long ans = 0;
        for (int i = 0; i < n; i ++) ok[i] = readInt();
        Arrays.sort(ok);
        for (int l = 0, r = n - 1; l < n / 2 - 1; l ++, r --) {
            ans += ok[r] * 2 - ok[l] * 2;
        }
        if (n % 2 == 0) ans += ok[n / 2] - ok[n / 2 - 1];
        else {
            int x = ok[n / 2 - 1], y = ok[n / 2], z = ok[n / 2 + 1];
            ans += Math.max(2 * z - x - y, z + y - x * 2);
        }
        System.out.println(ans);

    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}