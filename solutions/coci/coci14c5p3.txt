import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int k = readInt();
        int s = (int)1e5;
        int[] row = new int[s];
        int[] col = new int[s];
        int[] ld = new int[2 * s + 1];
        int[] rd = new int[2 * s + 1];
        for (int i = 1; i <= n; i ++) {
            int x = readInt() - 1;
            int y = readInt() - 1;
            row[x] ++;
            col[y] ++;
            ld[x + y] ++;
            rd[x + (s - 1) - y] ++;
            if (row[x] == k || col[y] == k || ld[x + y] == k || rd[x + (s - 1) - y] == k) {
                System.out.println(i);
                return;
            }
        }
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