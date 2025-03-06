import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        for (int q = 0; q < 10; q ++) {
            int n = readInt();
            int m = readInt();
            int d = readInt();
            int[] days = new int[m];
            for (int i = 0; i < m; i ++) {
                days[i] = readInt();
            }
            int c = n;
            int a = 0;
            for (int i = 1; i <= d; i ++) {
                if (c == 0) {
                    a ++;
                    c = n;
                }
                c --;
                for (int j = 0; j < m; j ++) {
                    if (days[j] == i) {
                        n ++;
                        c ++;
                    }
                }
            }
            System.out.println(a);
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