import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, q;
    static char[][] g;
    static boolean[][] v;
    public static void main(String[] args) throws IOException {
        n = readInt();
        q = readInt();
        g = new char[n][n];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                g[i][j] = readCharacter();
            }
        }
        for (int i = 0; i < q; i ++) {
            String w = br.readLine();
            boolean f = false;
            v = new boolean[n][n];
            outside:
            for (int r = 0; r < n; r ++) {
                for (int c = 0; c < n; c ++) {
                    if (g[r][c] == w.charAt(0)) {
                        f = f(r, c, 1, w);
                    }
                    if (f) {
                        break outside;
                    }
                }
            }
            System.out.println(f? "good puzzle!" : "bad puzzle!");
        }
    }
    static boolean f (int r, int c, int idx, String w) {
        if (idx >= w.length()) return true;
        v[r][c] = true;
        for (int dr = -1; dr <= 1; dr ++) {
            for (int dc = -1; dc <= 1; dc ++) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || v[nr][nc] || g[nr][nc] != w.charAt(idx)) continue;
                if (f(nr, nc, idx + 1, w)) return true;
            }
        }
        v[r][c] = false;
        return false;
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