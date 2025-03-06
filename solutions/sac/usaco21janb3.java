import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i ++) {
            c[i] = readInt();
        }
        int[] s = new int[n];
        for (int i = 0; i < n; i ++) {
            s[i] = readInt();
        }
        Arrays.sort(s);
        long ans = 1;
        for (int i = 0; i < n; i ++) {
            long x = 0;
            for (int cow : c) {
                if (cow <= s[i]) {
                    x ++;
                }
            }
            x -= i;
            ans *= x;
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}