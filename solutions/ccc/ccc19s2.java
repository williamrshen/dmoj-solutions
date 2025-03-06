import java.io.*;
import java.util.*;
public class Main {

    static int n = 2000000;
    static boolean[] prime = new boolean[n + 1];
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int t = readInt();
        sieve();
        for (int k = 0; k < t; k ++) {
            int N = readInt();
            for (int i = 1; i < N; i++) {
                if (prime[N + i] && prime[N - i]) {
                    int a = N + i;
                    int b = N - i;
                    System.out.println(a + " " + b);
                    break;
                }
            }
        }

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