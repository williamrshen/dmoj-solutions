import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Map<Integer, Integer> k = new HashMap<>();
    public static void main(String[] args) throws IOException {
        int n = ri();
        long out = 0;
        int[] j = new int[n];
        boolean[] g = new boolean[5000010];
        for (int i = 0; i < n; i ++) j[i] = ri();
        Arrays.sort(j);
        for (int i = 0; i < n; i ++) {
            if (!g[j[i]]) {
                out ++;
                for (int k = j[i]; k < 5000005; k += j[i]) {
                    g[k] = true;
                }
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