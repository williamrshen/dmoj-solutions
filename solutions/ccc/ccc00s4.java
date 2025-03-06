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
        int d = readInt();
        int n = readInt();
        int[] c = new int[n];
        int [] dp = new int[6000];
        for (int i = 0; i < n; i ++) {
            c[i] = readInt();
        }
        Arrays.fill(dp, 99999999);
        dp[0] = 0;
        for (int i = 0; i <= d; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i - c[j] >= 0) dp[i] = Math.min(dp[i], dp[i - c[j]] + 1);
            }
        }
        if (dp[d] != 99999999) System.out.print("Roberta wins in " + dp[d] + " strokes.");
        else System.out.print("Roberta acknowledges defeat.");
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