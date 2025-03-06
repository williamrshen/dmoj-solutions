import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int k = readInt(), n = readInt();
        for (int i = 0; i < n; i ++) {
            System.out.println(solve(k));
        }
    }

    static int solve (int d) throws IOException{
        int m = readInt();
        int l = 0;
        int r = 0;
        int t = 0;
        for (int i = 1;; i ++) {
            l += i;
            t ++;
            if (l + r >= d) return t;
            if (i >= m) {
                r += i;
                t ++;
                if (l + r >= d) return t;
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