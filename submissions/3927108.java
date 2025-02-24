import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long memo[];
    public static void main(String[] args) throws IOException {
        int n = readInt();
        System.out.println(quickpow(2, n / 2));
    }

    static long quickpow(long x, long n) {
        if(n == 0) return 1;
        long t = quickpow(x, n/2);
        t = t*t;
        if(n % 2 == 0) return t;
        return t*x;
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