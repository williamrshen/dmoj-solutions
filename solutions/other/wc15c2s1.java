import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt(), s[] = new int[n];
        for (int i = 0; i < n; i ++) s[i] = readInt();
        if (s[0] == 0) {
            if (s[1] != 1) s[0] = 1;
            else if (s[1] != 2) s[0] = 2;
            else if (s[1] != 3) s[0] = 3;
            else s[0] = 4;
        }
        for (int i = 1; i < n - 1; i ++) {
            if (s[i] == 0) {
                if (s[i - 1] != 1 && s[i + 1] != 1) {
                    s[i] = 1;
                }
                else if (s[i - 1] != 2 && s[i + 1] != 2) {
                    s[i] = 2;
                }
                else if (s[i - 1] != 3 && s[i + 1] != 3) {
                    s[i] = 3;
                }
                else s[i] = 4;
            }
        }
        if (s[n - 1] == 0) {
            if (s[n - 2] != 1) s[n - 1] = 1;
            else if (s[n - 2] != 2) s[n - 1] = 2;
            else if (s[n - 2] != 3) s[n - 1] = 3;
            else s[n - 1] = 4;
        }
        for (int x : s) System.out.print(x);
        System.out.println();
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