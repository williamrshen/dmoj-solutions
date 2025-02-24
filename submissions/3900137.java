import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int count = 0;
    public static void main(String[] args) throws IOException {
        n = readInt();
        for (int i = 1; i <= n/2; i ++) {
            f(i, i, n + "=" + i);
        }
        System.out.println("total=" + count);
    }

    static void f (int p, int s, String a) {
        if (s == n) {
            System.out.println(a);
            count ++;
            return;
        }
        for (int i = p; i + s <= n; i ++) {
            f(i, i + s, a + "+" + i);
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