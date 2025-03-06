import sun.security.provider.certpath.AdjacencyList;

import java.io.*;
import java.util.*;
public class Main {

    static int n = 100001;
    static boolean [] prime = new boolean[n + 1];
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        sieve();
        int[] psa = new int[n + 1];
        psa[1] = psa[0] = 0;
        psa[2] = 2;
        for (int i = 2; i <= n; i ++) {
            if (prime[i]) {
                psa[i] = psa[i - 1] + i;
            }
            else psa[i] = psa[i - 1];
        }

        int q = readInt();
        for (int i = 0; i < q; i ++) {
            int a = readInt(), b = readInt();
            System.out.println(psa[b] - psa[a - 1]);
        }

    }

    static void sieve () {
        Arrays.fill(prime, true);
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
}