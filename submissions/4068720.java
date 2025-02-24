import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final long max = (long)1e6;
    public static void main(String[] args) throws IOException {

        long k = readLong();
        if (k == 0) {
            System.out.println(1);
            System.out.println(1);
            return;
        }
        Map<Long, Long> m = new HashMap<>();
        for (long i = 0; i <= max; i ++) m.put(i * (i + 1) / 2, i);
        for (long i = 1; i <= max; i ++) {
            long r = k - i * (i + 1) / 2;
            if (!m.containsKey(r)) continue;
            long a = i, b = m.get(r);
            if (b > 0) {
                if (a + b + 1 > max) continue;
                System.out.println(a + b + 1);
                for (int x = 0; x < a; x ++) {
                    System.out.print(0 + " ");
                }
                System.out.print(1 + " ");
                for (int x = 0; x < b - 1; x ++) {
                    System.out.print(0 + " ");
                }
                System.out.println(0);
            }
            else {
                System.out.println(a);
                for (int x = 0; x < a - 1; x ++) {
                    System.out.print(0 + " ");
                }
                System.out.println(0);
            }
            return;
        }
        System.out.println(-1);
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
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