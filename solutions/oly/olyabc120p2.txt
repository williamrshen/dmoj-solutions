import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        long a = readLong();
        long b = readLong();
        int k = readInt();
        long x = gcd(a, b);
        List<Long> list = new ArrayList<>();
        for (long i = 1; i * i <= x; i ++) {
            if (x % i == 0) {
                list.add((long)i);
                if (x / i != i) list.add( x / i);
            }
        }
        Collections.sort(list, Collections.reverseOrder());
        if (k > list.size()) System.out.println(-1);
        else System.out.println(list.get(k - 1));
    }

    static long gcd (long a, long b) {
        if (a == 0) return b;
        return gcd(b%a, a);
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