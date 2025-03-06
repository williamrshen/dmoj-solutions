import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long memo[];
    public static void main(String[] args) throws IOException {
        List<Long> l = new ArrayList();
        long n = readLong();
        l.add((long)0);
        for (int i = 0; ; i ++) {
            long t = l.get(i) * 10 + 2;
            if (t <= n) l.add(t);
            else break;
            t = l.get(i) * 10 + 3;
            if (t <= n) l.add(t);
            else break;
        }
        System.out.println(l.size() - 1);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}