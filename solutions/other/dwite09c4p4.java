import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        String[] x = new String[50000];
        for (int i = 0; i < 50000; i ++) {
            char[] ok = String.valueOf(i).toCharArray();
            int s = 0;
            for (char k : ok) s += k + 1 - '1';
            x[i] = String.valueOf((s * i) % 99999);
        }
        for (int k = 0; k < 5; k ++) {
            int ans = 0;
            String n = next();
            for (String i : x) {
                if (i.length() < n.length()) continue;
                if (i.substring(0, n.length()).equals(n)) {
                    ans ++;
                }
            }
            System.out.println(ans);
        }

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