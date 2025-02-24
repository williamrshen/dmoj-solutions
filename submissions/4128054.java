import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static char[][] g;
    public static void main(String[] args) throws IOException {
        int n = ri(), m = ri();
        g = new char[n][m];
        for (int i = 0; i < n; i ++) {
            g[i] = readLine().toCharArray();
        }
        if (!legit(n, m)) {
            System.out.println(-1);
        }
        else {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    if (g[i][j] == '.') {
                        g[i][j] = g[i][m - j - 1] = 'z';
                    }
                }
            }
            for (char[] x : g) {
                for (char y : x) {
                    System.out.print(y);
                }
                System.out.println();
            }
        }
    }


    static boolean legit (int n, int m) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (g[i][j] == '.') continue;
                else {
                    if (g[i][j] != g[i][m - j - 1] && g[i][m - j - 1] != '.') {
                        return false;
                    }
                    else g[i][m - j - 1] = g[i][j];
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (g[j][i] == '.') continue;
                else {
                    if (g[j][i] != g[n - j - 1][i] && g[n - j - 1][i] != '.') {
                        return false;
                    }
                    else g[n - j - 1][i] = g[j][i];
                }
            }
        }
        return true;
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