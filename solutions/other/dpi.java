import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        double[] c = new double[n + 1];
        double[][] p = new double[n + 10][n + 10];
        for (int i = 1; i <= n; i ++) {
            c[i] = readDouble();
        }
        p[0][0] = 1;
        for (int i = 1; i <= n; i ++) {
            p[0][i] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            p[i][0] = p[i - 1][0]*(1 - c[i]);
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                p[i][j] = (p[i - 1][j - 1] * c[i]) + p[i - 1][j] * (1 - c[i]);
            }
        }
        double ans = 0.0;
        for (int j = n/2+1; j <= n; j++) {
            ans += p[n][j];
        }
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}