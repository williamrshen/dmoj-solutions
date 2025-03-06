import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long[] memo = new long[60];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        long aa = 0;
        int bb = 0;
        char[] a = br.readLine().toLowerCase().toCharArray(), b = br.readLine().toLowerCase().toCharArray();
        for (int i = 0; i < a.length; i ++) {
//            int x = (a[i] - 96)%10;
//            if (x == 0) x += 10;
//            aa += (int)Math.pow(x, i);
//            aa = aa%10;
//            if (aa == 0) aa += 10;
            aa += quickpow(a[i] - 96, i + 1, 10);
        }
        for (int i = 0; i < b.length; i ++) {
//            int x = (b[i] - 96)%10;
//            if (x == 0) x += 10;
//            bb += (int)Math.pow(x, i);
//            bb = bb%10;
//            if (bb == 0) bb += 10;
            bb += quickpow(b[i] - 96, i + 1, 10);
        }
//        System.out.println(aa);
//        System.out.println(bb);
        aa %= 10;
        bb %= 10;
        if (aa == 0) aa += 10;
        if (bb == 0) bb += 10;
        System.out.println(bb + aa);
    }

    static long quickpow(long x, long n, long mod) {
        if(n == 0) return 1;
        long t = quickpow(x, n/2, mod);
        t = t*t % mod;
        if(n % 2 == 0) return t;
        return t*x % mod;
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