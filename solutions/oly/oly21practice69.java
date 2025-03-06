import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt();
        int[][] r = new int[n][m];
        int max = -1;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                int t = readInt();
                if (t > max) max = t;
                r[i][j] = t;
            }
        }
        long count = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                count += max - r[i][j];
            }
        }
        System.out.println(count);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}