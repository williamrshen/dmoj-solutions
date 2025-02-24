import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), a[] = new int[n], ans = 0;
        for (int i = 0; i < n; i ++) a[i] = readInt();
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] != a[r]) {
                if (a[l] < a[r]) {
                    a[l + 1] += a[l];
                    l ++;
                }
                else {
                    a[r - 1] += a[r];
                    r --;
                }
                ans ++;
            }
            else { l ++; r --; }
        }
        System.out.println(ans);
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