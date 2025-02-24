import java.io.*;
import java.util.*;
public class Main {

    static int n = 2000000;
    static boolean[] prime = new boolean[n + 1];
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        sieve();
        for (int k = 0; k < 5; k ++) {
            int N = readInt();
            boolean h = true;
            for (int i = 2; i <= N; i++) {
                if (!prime[i]) continue;
                if (h) h = false;
                else System.out.print(" * ");
                System.out.print(i + "^" + factors(N, i));
            }
            System.out.println();
        }

    }

    static int factors (int n, int p) {
        int r = 0;
        for ( ; n >= p; n /= p) {
            r += n / p;
        }
        return r;
    }


    static void sieve () {
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i ++) {
            if (prime[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}