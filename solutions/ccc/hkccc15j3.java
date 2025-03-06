import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt(), count = n*n;
        boolean[] col = new boolean[n + 2];
        boolean[] row = new boolean[n + 2];
        boolean[] ld = new boolean[2 * n + 1];
        boolean[] rd = new boolean[2 * n + 1];
        for (int i = 0; i < m; i ++) {
            int x = readInt();
            int y = readInt();
            col[y] = true;
            row[x] = true;
            ld[x + y - 1] = true;
            rd[n + (x - y)] = true;
        }
        for (int i = 1; i < n + 1; i ++) {
            for (int j = 1; j < n + 1; j ++) {
                if (col[j] || row[i] || ld[i + j - 1] || rd[n + (i - j)]) count --;
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}